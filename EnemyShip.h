#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "HealthComponent.h"
#include "BoxComponent.h"
class EnemyShip :
    public GameObject
{
public:
	EnemyShip();

	EnemyShip(exVector3 location);

	virtual void Initialize() override;
};

