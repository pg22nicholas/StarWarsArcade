#pragma once
#include <vector>
#include "ShapeComponent.h"

class CircleComponent : public ShapeComponent
{
public:
	static std::vector<CircleComponent*> AllCircleComponents;
	CircleComponent(GameObject* Owner, float radius);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;
	float GetRadius();

	virtual void Render();

private:

	float mRadius;
};

