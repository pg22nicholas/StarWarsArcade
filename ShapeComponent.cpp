#include "ShapeComponent.h"
#include "Engine/Public/EngineTypes.h"
ShapeComponent::ShapeComponent(GameObject* Owner, bool isBackground) :Component(Owner), bIsBackground(isBackground)
{
	mC.mColor[0] = 0;
	mC.mColor[1] = 255;
	mC.mColor[2] = 0;
	mC.mColor[3] = 255;
}

void ShapeComponent::Initialize()
{
	// TODO
}

void ShapeComponent::Destroy()
{
	// TODO
}

ComponentTypes ShapeComponent::GetType()
{
	return ComponentTypes::Empty;
}

void ShapeComponent::SetColor(ColorTypes colorType)
{
	switch (colorType)
	{
	case ColorTypes::RED:
		mC.mColor[0] = 255;
		mC.mColor[1] = 0;
		mC.mColor[2] = 0;
		mC.mColor[3] = 255;
		break;
	case ColorTypes::GREEN:
		mC.mColor[0] = 0;
		mC.mColor[1] = 255;
		mC.mColor[2] = 0;
		mC.mColor[3] = 255;
		break;
	case ColorTypes::BLUE:
		mC.mColor[0] = 0;
		mC.mColor[1] = 0;
		mC.mColor[2] = 255;
		mC.mColor[3] = 255;
		break;
	case ColorTypes::BLACK:
		mC.mColor[0] = 0;
		mC.mColor[1] = 0;
		mC.mColor[2] = 0;
		mC.mColor[3] = 255;
		break;
	case ColorTypes::WHITE:
		mC.mColor[0] = 255;
		mC.mColor[1] = 255;
		mC.mColor[2] = 255;
		mC.mColor[3] = 255;
		break;
	default:
		break;
	}
}

void ShapeComponent::SetColor(exColor color)
{
	mC = color;
}
