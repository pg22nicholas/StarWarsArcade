// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "ControllerComponent.h"

std::vector<ControllerComponent*> ControllerComponent::AllGameControllerComponents;
// All controllers get added to a list on init and removed on destroy
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
