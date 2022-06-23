#include "Score.h"

Score::Score(GameObject* parent):GameObject(exVector3(-400, 250, 0), parent), mScore(0)
{
	Initialize();
}

void Score::Initialize()
{
	mTextComponent = new TextComponent(this, "Hello", StateType::Running);
	AddComponent(mTextComponent);
	GameObject::Initialize();
}

void Score::Update(float deltaTime)
{
	mScore = PlayerManager::GetManager()->GetScore();
	mTextComponent->SetText("Score: " + std::to_string((int)mScore));

	GameObject::Update(deltaTime);
}
