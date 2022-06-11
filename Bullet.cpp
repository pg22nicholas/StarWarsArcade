#include "Bullet.h"
#include "CircleComponent.h"
#include "PhysicsComponent.h"

Bullet::Bullet() : GameObject()
{
}

//Overriden from the Ball class.
void Bullet::Initialize()
{
	//Added a Circle COmponent to our Ball;
	AddComponent(new CircleComponent(this, 20.0f));
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, exVector3(100, 0, 0)));
	mTransform->SetPosition(exVector3(0, 300, 0));

	PhysicsComponent* MyPhysicsComponent = FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	MyPhysicsComponent->AddColissionEventLitsner(this);
	GameObject::Initialize();
}


//Collision Event Litsner
void Bullet::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	// TODO: Update Position?
	FindComponent<CircleComponent>(ComponentTypes::Circle)->SetColor(ColorTypes::RED);
}