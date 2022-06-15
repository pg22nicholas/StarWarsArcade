#pragma once
#include "GameObject.h"
#include "BoxComponent.h"

class Skybox :
    public GameObject
{
public:
	Skybox();

	virtual void Initialize() override;

private:
	const int kNumStars = 100;
};

