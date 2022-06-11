#include "CircleComponent.h"
#include "Game/Private/PlayerManager.h"

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
	exVector3 position = mOwningGameObject->GetTransform()->GetPosition();

	// Keep position local to player camera
	position.x -= PlayerManager::GetManager()->GetPlayer()->GetTransform()->GetPosition().x;

	// gets its z percent size based on z distance
	float zPercent = Bounds::zSizePercentage(position.z);
	AccessEngine()->DrawCircle(position.getExVector2(), mRadius * zPercent, mC, 0);
}
