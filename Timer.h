#pragma once
#include "GameObject.h"
#include "TextComponent.h"
class Timer :
    public GameObject
{
public:

	Timer(GameObject* parent, float maxTime);

	virtual void Initialize() override;
	virtual void Update(float deltaTime) override;

private:
	float mCurrentTime;
	float mMaxTime;
	TextComponent* mTextComponent;
};

