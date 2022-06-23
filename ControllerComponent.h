// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include <vector>
#include "GameObject.h"

// Base class for controllers
// Does nothing, but gets inherited by PlayerController and ReticleController
class ControllerComponent : public Component
{
public:
	static std::vector<ControllerComponent*> AllGameControllerComponents;
	ControllerComponent(GameObject* Owner);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void ReadInput(const uint8_t* pState) = 0;
	virtual void ParseInput() = 0;
};

