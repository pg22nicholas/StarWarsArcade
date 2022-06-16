#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Bounds.h"

class exColor;

enum class ColorTypes;

class ShapeComponent : public Component
{
public:
	ShapeComponent(GameObject* Owner, bool isBackground);

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render() = 0;

	void SetColor(ColorTypes colorType);
	void SetColor(exColor color);

protected:
	exColor mC;
	bool bIsBackground;
};

enum class ColorTypes {
	RED,
	GREEN,
	BLUE,
	BLACK,
	WHITE
};

