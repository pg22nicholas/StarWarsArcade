#pragma once
#include <vector>
#include "ShapeComponent.h"
#include "Transform.h"

class BoxComponent : public ShapeComponent
{
public:
	static std::vector<BoxComponent*> AllGameBoxComponents;
	BoxComponent(GameObject* Owner, float width, float height, bool isBackground = false);
	virtual void Initialize() override;
	virtual void Update(float deltaTime) override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void Render();
	float GetWidth();
	float GetHeight();

private:

	float mWidth;
	float mHeight;
};

