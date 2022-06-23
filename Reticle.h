// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "Game/Private/Utils.h"
#include "Bounds.h"
#include "CircleComponent.h"
#include "PhysicsComponent.h"
#include "ReticleController.h"

// The player's aiming reticle
class Reticle :
    public GameObject
{
public:
	Reticle(GameObject* parent);

	virtual void Initialize() override;
};

