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
	AddComponent(new PhysicsComponent(this, true, 0.5f, 5.0f, exVector2{ 100, 0 }));
	mTransform->SetPosition(exVector2{ 0, 300 });

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