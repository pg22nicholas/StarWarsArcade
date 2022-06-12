#include "ControllerComponent.h"

std::vector<ControllerComponent*> ControllerComponent::AllGameControllerComponents;
ControllerComponent::ControllerComponent(GameObject* Owner) : Component(Owner) {}

void ControllerComponent::Initialize()
{
	ControllerComponent::AllGameControllerComponents.push_back(this);
}

void ControllerComponent::Destroy()
{
	ControllerComponent::AllGameControllerComponents.erase(std::remove(ControllerComponent::AllGameControllerComponents.begin(), ControllerComponent::AllGameControllerComponents.end(), this), ControllerComponent::AllGameControllerComponents.end());
}

ComponentTypes ControllerComponent::GetType()
{
	return ComponentTypes::Controller;
}
