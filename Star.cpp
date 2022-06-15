#include "Star.h"

const float Star::kSize = 5;
Star::Star(exVector2 flatPosition, GameObject* parent):GameObject(exVector3(flatPosition.x, flatPosition.y, 0), parent)
{
	Initialize();
}

void Star::Initialize()
{
	CircleComponent* starShape = new CircleComponent(this, kSize, true, true);
	starShape->SetColor(ColorTypes::WHITE);
	AddComponent(starShape);

	GameObject::Initialize();
}