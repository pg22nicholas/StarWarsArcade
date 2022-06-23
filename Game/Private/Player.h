// Copyright (C) 2022 Nicholas Johnson, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "ControllerComponent.h"
#include "HealthComponent.h"
#include "Utils.h"
#include "Reticle.h"

class Player : public GameObject
{
public:
	Player();

	virtual void Initialize() override;
	static const int kMaxTime = 60;

private:

	float mMovementSpeed = 100;
	GameObjectHandle* mReticle;
};



