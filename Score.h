// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "TextComponent.h"
#include "Game/Private/PlayerManager.h"

// Game object to print the player's score
class Score :
    public GameObject
{
public:

	Score(GameObject* parent);

	virtual void Initialize() override;
	virtual void Update(float deltaTime) override;

private:
	float mScore;
	TextComponent* mTextComponent;
};

