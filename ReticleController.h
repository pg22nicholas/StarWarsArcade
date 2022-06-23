// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include <vector>
#include "ControllerComponent.h"
#include "PhysicsComponent.h"
#include "AttackComponent.h"
#include "GameObject.h"
#include "Bounds.h"
#include "SDL2-2.0.3/include/SDL_scancode.h"
#define LEFT_INPUT 0
#define RIGHT_INPUT 1
#define UP_INPUT 2
#define DOWN_INPUT 3
#define FIRE_INPUT 4

class ReticleController :
    public ControllerComponent
{
public:
	ReticleController(GameObject* Owner);

	virtual void ReadInput(const uint8_t* pState) override;
	virtual void ParseInput() override;
	void Update(float deltaTime) override;

private:
	exVector3 GetAimDirection();
	bool bIsFireHeld;
	int mReticleInput;
	float mSpeed = 400;
};