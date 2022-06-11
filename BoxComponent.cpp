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
	topLeft.x = x - mWidth / 2; 
	topLeft.y = y - mHeight / 2;

	exVector2 bottomRight;
	bottomRight.x = x + mWidth / 2;
	bottomRight.y = y + mHeight / 2;

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
