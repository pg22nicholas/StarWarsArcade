// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "BoxComponent.h"

// Gameobject to render sky and stars
class Skybox :
    public GameObject
{
public:
	Skybox();

	virtual void Initialize() override;

private:
	const int kNumStars = 100;
};

