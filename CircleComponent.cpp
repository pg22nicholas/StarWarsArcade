#include "CircleComponent.h"

std::vector<CircleComponent*> CircleComponent::AllCircleComponents;

CircleComponent::CircleComponent(GameObject* Owner, float radius) :ShapeComponent(Owner), mRadius(radius)
{
}

void CircleComponent::Initialize()
{
	CircleComponent::AllCircleComponents.push_back(this);
}

void CircleComponent::Destroy()
{
	CircleComponent::AllCircleComponents.erase(std::remove(CircleComponent::AllCircleComponents.begin(), CircleComponent::AllCircleComponents.end(), this), CircleComponent::AllCircleComponents.end());
}

ComponentTypes CircleComponent::GetType()
{
	return ComponentTypes::Circle;
}

float CircleComponent::GetRadius()
{
	return mRadius;
}

void CircleComponent::Render()
{ 
	exVector2 position = mOwningGameObject->GetTransform()->GetPosition();
	AccessEngine()->DrawCircle(position, mRadius, mC, 0);
}
