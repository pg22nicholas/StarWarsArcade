#pragma once
#include "GameObject.h"
#include "Game/Private/Utils.h"
#include "Bounds.h"
#include "CircleComponent.h"

class Reticle :
    public GameObject
{
public:
	Reticle();

	virtual void Initialize() override;

	void ApplyMovement(MOVEMENT movement);
};

