// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "ShipWing.h"
#include "PhysicsComponent.h"
#include "HealthComponent.h"
#include "CircleComponent.h"

class EnemyShip :
    public GameObject
{
public:
	EnemyShip();
	EnemyShip(exVector3 location, exVector3 direction);

	virtual void Initialize() override;

	void OnDestroy() override;

private:

	int mShipID;
};

