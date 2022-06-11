#include "Ball.h"
#include "CircleComponent.h"
#include "PhysicsComponent.h"

Ball::Ball() : GameObject()
{
}

void Ball::Initialize()
{
	AddComponent(new CircleComponent(this, 50.0f));
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, exVector2()));
	
	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}


// Collision Event Litsner
void Ball::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	FindComponent<CircleComponent>(ComponentTypes::Circle)->SetColor(ColorTypes::RED);
}
