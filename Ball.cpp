#include "Ball.h"
#include "CircleComponent.h"
#include "PhysicsComponent.h"

Ball::Ball() : GameObject()
{
}

//Overriden from the Ball class.
void Ball::Initialize()
{
	//Added a Circle COmponent to our Ball;
	AddComponent(new CircleComponent(this, 50.0f));
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, exVector2()));
	
	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}


//Collision Event Litsner
void Ball::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	// TODO: Update Position?
	FindComponent<CircleComponent>(ComponentTypes::Circle)->SetColor(ColorTypes::RED);
}
