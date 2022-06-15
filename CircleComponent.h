#pragma once
#include <vector>
#include "ShapeComponent.h"

class CircleComponent : public ShapeComponent
{
public:
	static std::vector<CircleComponent*> AllCircleComponents;
	CircleComponent(GameObject* Owner, float radius, bool isFilled = true, bool isBackground = false);
	CircleComponent(GameObject* Owner, float radius, exColor color, bool isFilled = true, bool isBackground = false);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;
	float GetRadius();

	virtual void Render();

private:

	float mRadius;
	bool bIsFilled;
};

