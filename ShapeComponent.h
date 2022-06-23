#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Bounds.h"
#include "Game/Private/Utils.h"

enum class ColorTypes;

class ShapeComponent : public Component
{
public:
	ShapeComponent(GameObject* Owner, StateType renderState, bool isBackground);

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render(const StateType& state) = 0;

	void SetColor(ColorTypes colorType);

protected:
	exColor mC;
	bool bIsBackground;
	StateType mRenderState;
};

enum class ColorTypes {
	RED,
	GREEN,
	BLUE,
	BLACK,
	WHITE
};

