#include "CircleComponent.h"
#include "Game/Private/PlayerManager.h"
#include "RenderManager.h"

std::vector<CircleComponent*> CircleComponent::AllCircleComponents;

CircleComponent::CircleComponent(GameObject* Owner, float radius, bool isFilled, bool isBackground) :ShapeComponent(Owner, isBackground), mRadius(radius), bIsFilled(isFilled)
{
}

CircleComponent::CircleComponent(GameObject* Owner, float radius, exColor color, bool isFilled, bool isBackground) :ShapeComponent(Owner, isBackground), mRadius(radius), bIsFilled(isFilled)
{
	mC = color;
}

void CircleComponent::Initialize()
{
	CircleComponent::AllCircleComponents.push_back(this);
}

void CircleComponent::Update(float deltaTime) {}

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
	exVector3 position = RenderManager::GetManager()->GetRenderPosition(mOwningGameObject->GetTransform()->GetLocalPosition());

	// gets its z percent size based on z distance
	float zPercent = Bounds::zSizePercentage(position.z);
	if(bIsFilled)
		AccessEngine()->DrawCircle(position.getExVector2(), mRadius * zPercent, mC, (bIsBackground ? (Bounds::zBounds + 1) : position.z));
	else

		AccessEngine()->DrawLineCircle(position.getExVector2(), mRadius * zPercent, mC, (bIsBackground ? (Bounds::zBounds + 1) : position.z));
}

void CircleComponent::SetRadius(float radius)
{
	mRadius = radius;
}
