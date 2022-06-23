#pragma once
#include "GameObject.h"
#include "TextComponent.h"
#include "Game/Private/PlayerManager.h"

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
