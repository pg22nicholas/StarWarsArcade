#include "ShapeComponent.h"

ShapeComponent::ShapeComponent(GameObject* Owner) :Component(Owner)
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
	case RED:
		mC.mColor[0] = 255;
		mC.mColor[1] = 0;
		mC.mColor[2] = 0;
		mC.mColor[3] = 255;
		break;
	case GREEN:
		mC.mColor[0] = 0;
		mC.mColor[1] = 255;
		mC.mColor[2] = 0;
		mC.mColor[3] = 255;
		break;
	case BLUE:
		mC.mColor[0] = 0;
		mC.mColor[1] = 0;
		mC.mColor[2] = 255;
		mC.mColor[3] = 255;
		break;
	default:
		break;
	}
}
