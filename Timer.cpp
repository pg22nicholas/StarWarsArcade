// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "Timer.h"
#include "Game/Private/PlayerManager.h"
#include <string>

Timer::Timer(GameObject* parent, float maxTime): GameObject(exVector3(-400, -300, 0), parent)
{
	Initialize();
}

void Timer::Initialize()
{
	mTextComponent = new TextComponent(this, "Hello", StateType::Running);
	AddComponent(mTextComponent);
	GameObject::Initialize();
}

// Gets max and elapsed time and shows the difference
void Timer::Update(float deltaTime)
{
	mTextComponent->SetText("Time: " + std::to_string((int)(PlayerManager::GetManager()->GetPlayer()->kMaxTime - PlayerManager::GetManager()->mElapsedTime)));

	GameObject::Update(deltaTime);
}
