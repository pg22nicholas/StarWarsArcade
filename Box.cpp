#include "Box.h"
#include "BoxComponent.h"
#include "PhysicsComponent.h"

Box::Box() : GameObject()
{
}

//Overriden from the Ball class.
void Box::Initialize()
{
	//Added a s quare Component to our Ball;
	AddComponent(new BoxComponent(this, 50, 50));
	exVector2 velocity;
	velocity.x = 40;
	velocity.y = 0;
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, velocity));

	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}


//Collision Event Litsner
void Box::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	// TODO: Update Position
	FindComponent<BoxComponent>(ComponentTypes::Box)->SetColor(ColorTypes::RED);
}