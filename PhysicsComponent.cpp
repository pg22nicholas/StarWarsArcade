#include "PhysicsComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "BoxComponent.h"
#include "CircleComponent.h"
#include <math.h> 

PhysicsComponent::PhysicsComponent(GameObject* OwningGameObject, bool gravityEnabled, float gravityScale, float mass, exVector2 Velocity, bool collisionEnabled) :Component(OwningGameObject)
{
	bGravityEnabled = gravityEnabled;
	mGravityScale = gravityScale;
	mMass = mass;
	mVelocity = Velocity;
	bIsCollisionEnabled = collisionEnabled;
}

void PhysicsComponent::Initialize()
{
	mAllPhysicsComponents.push_back(this);
}

void PhysicsComponent::Destroy()
{
	PhysicsComponent::mAllPhysicsComponents.erase(std::remove(PhysicsComponent::mAllPhysicsComponents.begin(), PhysicsComponent::mAllPhysicsComponents.end(), this), PhysicsComponent::mAllPhysicsComponents.end());
}

ComponentTypes PhysicsComponent::GetType()
{
	return ComponentTypes::Physics;
}

bool PhysicsComponent::IsColliding(PhysicsComponent* OtherPhysicsComponent)
{
	//return bIsCollisionEnabled;
	BoxComponent* MyBoxComp = mOwningGameObject->FindComponent<BoxComponent>(ComponentTypes::Box);
	CircleComponent* MyCircleComp = mOwningGameObject->FindComponent<CircleComponent>(ComponentTypes::Circle);
	BoxComponent* OtherBoxComp = OtherPhysicsComponent->mOwningGameObject->FindComponent<BoxComponent>(ComponentTypes::Box);
	CircleComponent* OtherCircleComp = OtherPhysicsComponent->mOwningGameObject->FindComponent<CircleComponent>(ComponentTypes::Circle);

	if (MyCircleComp != nullptr && OtherCircleComp != nullptr)
	{
		exVector2 pos1 = MyCircleComp->GetGameObject()->GetTransform()->GetPosition();
		float radius1 = MyCircleComp->GetRadius();
		
		exVector2 pos2 = OtherCircleComp->GetGameObject()->GetTransform()->GetPosition();
		float radius2 = OtherCircleComp->GetRadius();

		// circles collision check using radius and distance
		float distX = pos1.x - pos2.x;
		float distY = pos1.y - pos2.y;
		float distance = sqrt((distX * distX) + (distY * distY));
		return distance <= radius1 + radius2;
	}
	if (MyBoxComp != nullptr && OtherBoxComp != nullptr)
	{
		exVector2 box1 = MyBoxComp->GetGameObject()->GetTransform()->GetPosition();
		float box1H = MyBoxComp->GetHeight();
		float box1W = MyBoxComp->GetWidth();
		exVector2 box2 = OtherBoxComp->GetGameObject()->GetTransform()->GetPosition();
		float box2H = OtherBoxComp->GetHeight();
		float box2W = OtherBoxComp->GetWidth();

		// AABB collision check
		return (box1.x <= box2.x + box2W &&
			box1.x + box1W >= box2.x &&
			box1.y <= box2.y + box2H &&
			box1H + box1.y >= box2.y);
	}
	if (MyCircleComp != nullptr && OtherBoxComp != nullptr)
	{
		return CircleSquareCollisionCheck(MyCircleComp, OtherBoxComp);
	}
	if (MyBoxComp != nullptr && OtherCircleComp != nullptr)
	{
		return CircleSquareCollisionCheck(OtherCircleComp, MyBoxComp);
	}

	return false;
}

// Collision check for a square against a circle
bool PhysicsComponent::CircleSquareCollisionCheck(CircleComponent* circleComp, BoxComponent* boxComp)
{
	exVector2 circle = circleComp->GetGameObject()->GetTransform()->GetPosition();
	float circleRadius = circleComp->GetRadius();
	exVector2 box = boxComp->GetGameObject()->GetTransform()->GetPosition();
	float boxHeight = boxComp->GetHeight();
	float boxWidth = boxComp->GetWidth();

	exVector2 circleDistance;
	circleDistance.x = abs(circle.x - box.x);
	circleDistance.y = abs(circle.y - box.y);

	// circle in x/y direction too far
	if (circleDistance.x > (boxWidth / 2 + circleRadius)) { return false; }
	if (circleDistance.y > (boxHeight / 2 + circleRadius)) { return false; }

	// circle center inside the box
	if (circleDistance.x <= (boxWidth / 2)) { return true; }
	if (circleDistance.y <= (boxHeight / 2)) { return true; }

	// Check for intersection on the corner of the square
	// calculate the corner of the square and check if the length is less than the radius
	float cornerDistance_sq = ((circleDistance.x - boxWidth / 2) * (circleDistance.x - boxWidth / 2)) +
		((circleDistance.y - boxHeight / 2) * (circleDistance.y - boxHeight / 2));

	return (cornerDistance_sq <= (circleRadius * circleRadius));
}


void PhysicsComponent::Update(float pDeltaTime)
{
	// Update position based on velocity
	exVector2 currPos = mOwningGameObject->GetTransform()->GetPosition();
	currPos.x += mVelocity.x * pDeltaTime;
	currPos.y += mVelocity.y * pDeltaTime;
	mOwningGameObject->GetTransform()->SetPosition(currPos);

	// notify collision listeners if collision occured
	if (bIsCollisionEnabled)
	{
		for (PhysicsComponent* PhysicsComponentIterator : mAllPhysicsComponents)
		{
			if (PhysicsComponentIterator == this)
			{
				continue;
			}

			//TODO - Maybe have IsColliding Produce a ExVector2 that contains the Normal of the COllision
			if (IsColliding(PhysicsComponentIterator) && PhysicsComponentIterator->bIsCollisionEnabled)
			{
				// Adding Collision Check
				for (IPhysicsCollisionEvent* pCollisionEvent : mCollisionEvents)
				{
					pCollisionEvent->OnCollision(this, PhysicsComponentIterator);
				}
			}
		}
	}
}

void PhysicsComponent::AddColissionEventLitsner(IPhysicsCollisionEvent* pEvent)
{
	PhysicsComponent::mCollisionEvents.push_back(pEvent);
}

//You can move the Update / Is Colliding / add CollisionEventLitsner / the Static Event Litsner Array to a singleton

//std::vector<IPhysicsCollisionEvent*> PhysicsComponent::mCollisionEvents;
std::vector<PhysicsComponent*> PhysicsComponent::mAllPhysicsComponents;