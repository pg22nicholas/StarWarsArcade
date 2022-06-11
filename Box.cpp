#include "Box.h"
#include "BoxComponent.h"
#include "PhysicsComponent.h"

Box::Box() : GameObject()
{
}

void Box::Initialize()
{
	AddComponent(new BoxComponent(this, 50, 50));
	exVector3 velocity(40, 0, 0);
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, velocity));

	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}


//Collision Event Litsner
void Box::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	FindComponent<BoxComponent>(ComponentTypes::Box)->SetColor(ColorTypes::RED);
}