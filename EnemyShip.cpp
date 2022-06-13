#include "EnemyShip.h"

EnemyShip::EnemyShip(): GameObject(exVector3(rand() % 800, rand() % 600, 50)) {


	Initialize();
}

void EnemyShip::Initialize()
{

	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3::Zero()));
	AddComponent(new BoxComponent(this, 100, 100));
	AddComponent(new HealthComponent(this, 6, 1));
	GameObject::Initialize();
}
