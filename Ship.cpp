#include "Ship.h"
#include "BoxComponent.h"
#include "PhysicsComponent.h"

Ship::Ship() : GameObject()
{
}

//Overriden from the Ball class.
void Ship::Initialize()
{
	//Added a s quare Component to our Ball;
	AddComponent(new BoxComponent(this, 50, 50));
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, exVector2{ 40, 0}));
	mTransform->SetPosition(exVector2{ 400, 300 });

	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}

//Collision Event Litsner
void Ship::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	// TODO: Update Position
	FindComponent<BoxComponent>(ComponentTypes::Box)->SetColor(ColorTypes::RED);
}