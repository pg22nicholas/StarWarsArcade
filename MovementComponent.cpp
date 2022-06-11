#include "MovementComponent.h"

MovementComponent::MovementComponent(GameObject* Owner): Component(Owner) {}

void MovementComponent::Initialize() {}

void MovementComponent::Destroy() {}

ComponentTypes MovementComponent::GetType()
{
	return ComponentTypes::Movement;
}
