// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "TextComponent.h"
#include "RenderManager.h"

// Redefine macro because of a conflict in a windows file
#define DrawText AccessEngine()->DrawText

class EngineInterface;

std::vector<TextComponent*> TextComponent::AllTextComponents;
TextComponent::TextComponent(GameObject* Owner, std::string text, StateType renderState) :ShapeComponent(Owner, renderState, false), mText(text) {}

void TextComponent::Initialize()
{
	TextComponent::AllTextComponents.push_back(this);
}

void TextComponent::Update(float deltaTime) {}

void TextComponent::Destroy()
{
	TextComponent::AllTextComponents.erase(std::remove(TextComponent::AllTextComponents.begin(), TextComponent::AllTextComponents.end(), this), TextComponent::AllTextComponents.end());
}

ComponentTypes TextComponent::GetType()
{
	return ComponentTypes::Text;
}

void TextComponent::SetText(const std::string& newText)
{
	mText = newText;
}

// Draw text at the GO position
void TextComponent::Render(const StateType& state)
{
	if (state != mRenderState && mRenderState != StateType::None) return;
	exVector3 vec3Position = RenderManager::GetManager()->GetRenderPosition(mOwningGameObject->GetTransform()->GetLocalPosition());

	exVector2 vec2Position;
	vec2Position.x = vec3Position.x;
	vec2Position.y = vec3Position.y;

	DrawText(RenderManager::GetManager()->GetFontID(), vec2Position, mText.c_str(), mC, vec3Position.z);
}