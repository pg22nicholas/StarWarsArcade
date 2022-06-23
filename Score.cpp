// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "Score.h"

Score::Score(GameObject* parent):GameObject(exVector3(-400, 250, 0), parent), mScore(0)
{
	Initialize();
}

void Score::Initialize()
{
	// Render component renders regardless of state
	mTextComponent = new TextComponent(this, "", StateType::None);
	AddComponent(mTextComponent);
	GameObject::Initialize();
}

// Get score from the manager and print to screen
void Score::Update(float deltaTime)
{
	mScore = PlayerManager::GetManager()->GetScore();
	mTextComponent->SetText("Score: " + std::to_string((int)mScore));

	GameObject::Update(deltaTime);
}
