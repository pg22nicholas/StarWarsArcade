#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Bounds.h"

enum class ColorTypes;

class ShapeComponent : public Component
{
public:
	ShapeComponent(GameObject* Owner);

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render() = 0;

	void SetColor(ColorTypes colorType);

protected:
	exColor mC;
};

enum class ColorTypes {
	RED,
	GREEN,
	BLUE
};

