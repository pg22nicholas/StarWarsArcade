#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "HealthComponent.h"
#include "BoxComponent.h"
#include "CircleComponent.h"

class EnemyShip :
    public GameObject
{
public:
	EnemyShip();
	EnemyShip(exVector3 location, exVector3 direction);

	virtual void Initialize() override;
};

