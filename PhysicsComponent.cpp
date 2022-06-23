// Copyright (C) 2022 Nicholas Johnson, All Rights Reserved
#include "PhysicsComponent.h"
#include "Transform.h"
#include "GameObject.h"
#include "BoxComponent.h"
#include "CircleComponent.h"
#include <math.h> 

const float PhysicsComponent::zOverlapRange = 30;
PhysicsComponent::PhysicsComponent(GameObject* OwningGameObject, bool gravityEnabled, float gravityScale, float mass, exVector3 Velocity, bool collisionEnabled) :Component(OwningGameObject)
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

bool PhysicsComponent::IsColliding(PhysicsComponent* OtherPhysicsComponent, bool ignoreZ)
{
	BoxComponent* MyBoxComp = mOwningGameObject->FindComponent<BoxComponent>(ComponentTypes::Box);
	CircleComponent* MyCircleComp = mOwningGameObject->FindComponent<CircleComponent>(ComponentTypes::Circle);
	BoxComponent* OtherBoxComp = OtherPhysicsComponent->mOwningGameObject->FindComponent<BoxComponent>(ComponentTypes::Box);
	CircleComponent* OtherCircleComp = OtherPhysicsComponent->mOwningGameObject->FindComponent<CircleComponent>(ComponentTypes::Circle);

	if (MyCircleComp != nullptr && OtherCircleComp != nullptr)
	{
		exVector3 pos1 = MyCircleComp->GetGameObject()->GetTransform()->GetPosition();
		float radius1 = MyCircleComp->GetRadius() * Bounds::zSizePercentage(pos1.z);
		
		exVector3 pos2 = OtherCircleComp->GetGameObject()->GetTransform()->GetPosition();
		float radius2 = OtherCircleComp->GetRadius() * Bounds::zSizePercentage(pos2.z);

		// circles collision check using radius and distance
		float distX = pos1.x - pos2.x;
		float distY = pos1.y - pos2.y;
		float distance = sqrtf((distX * distX) + (distY * distY));
		bool zPlane = ((abs(pos1.z - pos2.z) <= zOverlapRange) || ignoreZ);
		return (distance <= radius1 + radius2 && zPlane);
	}
	if (MyBoxComp != nullptr && OtherBoxComp != nullptr)
	{
		exVector3 box1 = MyBoxComp->GetGameObject()->GetTransform()->GetPosition();
		float box1H = MyBoxComp->GetHeight() * Bounds::zSizePercentage(box1.z);
		float box1W = MyBoxComp->GetWidth() * Bounds::zSizePercentage(box1.z);
		exVector3 box2 = OtherBoxComp->GetGameObject()->GetTransform()->GetPosition();
		float box2H = OtherBoxComp->GetHeight() * Bounds::zSizePercentage(box2.z);
		float box2W = OtherBoxComp->GetWidth() * Bounds::zSizePercentage(box2.z);
		bool zPlane = ((abs(box1.z - box2.z) <= zOverlapRange) || ignoreZ);

		// AABB collision check
		return ((box1.x <= box2.x + box2W &&
			box1.x + box1W >= box2.x &&
			box1.y <= box2.y + box2H &&
			box1H + box1.y >= box2.y) && zPlane);
	}
	if (MyCircleComp != nullptr && OtherBoxComp != nullptr)
	{
		return CircleSquareCollisionCheck(MyCircleComp, OtherBoxComp, ignoreZ);
	}
	if (MyBoxComp != nullptr && OtherCircleComp != nullptr)
	{
		return CircleSquareCollisionCheck(OtherCircleComp, MyBoxComp, ignoreZ);
	}

	return false;
}

// Collision check for a square against a circle
bool PhysicsComponent::CircleSquareCollisionCheck(CircleComponent* circleComp, BoxComponent* boxComp, bool ignoreZ)
{
	exVector3 circle = circleComp->GetGameObject()->GetTransform()->GetLocalPosition();
	float circleRadius = circleComp->GetRadius() * Bounds::zSizePercentage(circle.z);
	exVector3 box = boxComp->GetGameObject()->GetTransform()->GetLocalPosition();
	float boxHeight = boxComp->GetHeight() * Bounds::zSizePercentage(circle.z);
	float boxWidth = boxComp->GetWidth() * Bounds::zSizePercentage(circle.z);

	exVector3 circleDistance;
	circleDistance.x = abs(circle.x - box.x);
	circleDistance.y = abs(circle.y - box.y);

	// circle in x/y direction too far
	if (circleDistance.x > (boxWidth / 2 + circleRadius)) { return false; }
	if (circleDistance.y > (boxHeight / 2 + circleRadius)) { return false; }


	bool zPlane = ((abs(circle.z - box.z) <= zOverlapRange) || ignoreZ);
	// circle center inside the box
	if (circleDistance.x <= (boxWidth / 2)) { return zPlane; }
	if (circleDistance.y <= (boxHeight / 2)) { return zPlane; }

	// Check for intersection on the corner of the square
	// calculate the corner of the square and check if the length is less than the radius
	float cornerDistance_sq = ((circleDistance.x - boxWidth / 2) * (circleDistance.x - boxWidth / 2)) +
		((circleDistance.y - boxHeight / 2) * (circleDistance.y - boxHeight / 2));


	return ((cornerDistance_sq <= (circleRadius * circleRadius)) && zPlane);
}


void PhysicsComponent::Update(float pDeltaTime)
{
	// Update position based on velocity
	exVector3 currPos = mOwningGameObject->GetTransform()->GetPosition();
	currPos += mVelocity * pDeltaTime;

	// Probably should be setting up handles before we start doing more memory management
	if (currPos.z > Bounds::zBounds || abs(currPos.x) > Bounds::xBounds + kViewportWidth/2 || abs(currPos.y) > Bounds::YBounds + kViewportHeight / 2) {
		mOwningGameObject->OnDestroy();
		return;
	}

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

exVector3 PhysicsComponent::GetVelocity()
{
	return mVelocity;
}

void PhysicsComponent::SetVelocity(exVector3 velocity)
{
	mVelocity = velocity;
}

GameObject* PhysicsComponent::Raycast()
{
	GameObject* result = nullptr;
	exVector3 position = mOwningGameObject->GetTransform()->GetPosition();
	for (PhysicsComponent* PhysicsComponentIterator : mAllPhysicsComponents)
	{
		if (PhysicsComponentIterator == this)
		{
			continue;
		}

		if (IsColliding(PhysicsComponentIterator, true) && PhysicsComponentIterator->bIsCollisionEnabled)
		{
			GameObject* GOIterator = PhysicsComponentIterator->mOwningGameObject;
			if (result == nullptr) result = GOIterator;
			else if (exVector3::Distance(GOIterator->GetTransform()->GetPosition(), position) < exVector3::Distance(result->GetTransform()->GetPosition(), position)) {
				result = GOIterator;
			}
		}
	}

	return result;
}

void PhysicsComponent::AddColissionEventLitsner(IPhysicsCollisionEvent* pEvent)
{
	PhysicsComponent::mCollisionEvents.push_back(pEvent);
}

std::vector<PhysicsComponent*> PhysicsComponent::mAllPhysicsComponents;