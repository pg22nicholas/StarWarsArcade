#include "BoxComponent.h"
#include "GameObject.h"


class EngineInterface;

std::vector<BoxComponent*> BoxComponent::AllGameBoxComponents;

BoxComponent::BoxComponent(GameObject* Owner, float width, float height) :ShapeComponent(Owner), mWidth(width)
, mHeight(height)
{
}

void BoxComponent::Initialize()
{
	BoxComponent::AllGameBoxComponents.push_back(this);
}

void BoxComponent::Destroy()
{
	BoxComponent::AllGameBoxComponents.erase(std::remove(BoxComponent::AllGameBoxComponents.begin(), BoxComponent::AllGameBoxComponents.end(), this), BoxComponent::AllGameBoxComponents.end());
}

ComponentTypes BoxComponent::GetType()
{
	return ComponentTypes::Box;
}

void BoxComponent::Render()
{
	exVector3 position = mOwningGameObject->GetTransform()->GetPosition();

	float x = position.x;
	float y = position.y;
	exVector2 topLeft;

	// Get the size based on its z distance
	float zPercent = Bounds::zSizePercentage(position.z);
	float widthBasedOnZ = mWidth * zPercent;
	float heightBasedOnZ = mHeight * zPercent;
	topLeft.x = x - widthBasedOnZ / 2;
	topLeft.y = y - heightBasedOnZ / 2;

	exVector2 bottomRight;
	bottomRight.x = x + widthBasedOnZ / 2;
	bottomRight.y = y + heightBasedOnZ / 2;

	AccessEngine()->DrawBox(topLeft, bottomRight, mC, 0);
}

float BoxComponent::GetWidth()
{
	return mWidth;
}

float BoxComponent::GetHeight()
{
	return mHeight;
}
