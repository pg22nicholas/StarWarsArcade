#include "EnemyShip.h"

EnemyShip::EnemyShip(): GameObject(exVector3(rand() % 800, rand() % 600, 50)) {

	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3::Zero()));
	Initialize();
}

EnemyShip::EnemyShip(exVector3 location, exVector3 direction) : GameObject(location)
{
	AddComponent(new PhysicsComponent(this, false, 0, 0, direction));
	Initialize();
}

void EnemyShip::Initialize()
{
	AddComponent(new BoxComponent(this, 100, 100));
	AddComponent(new HealthComponent(this, 6, 1));
	GameObject::Initialize();
}
