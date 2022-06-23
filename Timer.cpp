#include "Timer.h"
#include <string>

Timer::Timer(GameObject* parent, float maxTime): GameObject(exVector3(-400, -300, 0), parent), mCurrentTime(0), mMaxTime(maxTime)
{
	Initialize();
}

void Timer::Initialize()
{
	mTextComponent = new TextComponent(this, "Hello", StateType::Running);
	AddComponent(mTextComponent);
	GameObject::Initialize();
}

void Timer::Update(float deltaTime)
{
	mCurrentTime += deltaTime;
	mTextComponent->SetText("Time: " + std::to_string((int)(mMaxTime - mCurrentTime)));

	GameObject::Update(deltaTime);
}
