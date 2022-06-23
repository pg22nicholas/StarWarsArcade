// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "RestartText.h"

RestartText::RestartText(GameObject* parent) :GameObject(exVector3(-400, -300, 0), parent) 
{
	Initialize();
}

void RestartText::Initialize()
{
	AddComponent(new TextComponent(this, "Press 'R' to restart", StateType::GameOver));
	GameObject::Initialize();
}
