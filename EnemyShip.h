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

	virtual void Initialize() override;
};

