// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "EnemyShip.h"
#include "EnemyShipManager.h"

// Still ship at random location (for testing)
EnemyShip::EnemyShip(): GameObject(exVector3((float)(rand() % 800), (float)(rand() % 600), 50)) {

	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3::Zero()));
	Initialize();
}

// Moving ship
EnemyShip::EnemyShip(exVector3 location, exVector3 direction) : GameObject(location)
{
	AddComponent(new PhysicsComponent(this, false, 0, 0, direction));
	Initialize();
}

// Adds two boxes for body and wings, and a health component
void EnemyShip::Initialize()
{
	AddComponent(new BoxComponent(this, 100, 100));
	AddComponent(new BoxComponent(this, 200, 25));
	AddComponent(new HealthComponent(this, 6, 1));

	GameObject::Initialize();
}

void EnemyShip::OnDestroy()
{	
	EnemyShipManager::GetManager()->RemoveShip(mID);
	GameObject::OnDestroy();
}
