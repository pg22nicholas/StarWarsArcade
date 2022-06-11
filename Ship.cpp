#include "Ship.h"
#include "BoxComponent.h"
#include "PhysicsComponent.h"

Ship::Ship() : GameObject()
{
}

void Ship::Initialize()
{
	AddComponent(new BoxComponent(this, 50, 50));
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, exVector3{ 40, 0, 0}));
	mTransform->SetPosition(exVector3(400, 300, 0));

	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}

// Collision event listener
void Ship::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	FindComponent<BoxComponent>(ComponentTypes::Box)->SetColor(ColorTypes::RED);
}