// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "TextComponent.h"


// Simple game object that displays static text prompting player to restart
class RestartText: public GameObject
{
public:

	RestartText(GameObject* parent);

	virtual void Initialize() override;

private:
	float mScore;
	TextComponent* mTextComponent;
};

