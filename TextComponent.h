// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "ShapeComponent.h"
#include "State.h"
#include <iostream>

// Shape component to render text
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

	virtual void SetText(const std::string& newText);
	virtual void Render(const StateType& state) override;

private:
	std::string mText;
};

