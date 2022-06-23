// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "TextComponent.h"

// Game object to display the time remaining
class Timer :
    public GameObject
{
public:

	Timer(GameObject* parent, float maxTime);

	virtual void Initialize() override;
	virtual void Update(float deltaTime) override;

private:
	TextComponent* mTextComponent;
};

