#pragma once
#include "ShapeComponent.h"
#include "State.h"
#include <iostream>

class TextComponent :
    public ShapeComponent
{
public:
	static std::vector<TextComponent*> AllTextComponents;
	TextComponent(GameObject* Owner, std::string text, StateType renderState);
	virtual void Initialize() override;
	virtual void Update(float deltaTime) override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void SetText(std::string newText);
	virtual void Render();

private:
	std::string mText;
	StateType mRenderState;
};

