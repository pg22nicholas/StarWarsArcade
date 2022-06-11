#include "ControllerComponent.h"

std::vector<ControllerComponent*> ControllerComponent::AllGameControllerComponents;

ControllerComponent::ControllerComponent(GameObject* Owner) : Component(Owner), mLeft(false), mRight(false), mUp(false), mDown(false), mFire(false) {}

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

void ControllerComponent::ProccessInput(const uint8_t* pState)
{
	mUp |= pState[SDL_SCANCODE_UP];
	mDown |= pState[SDL_SCANCODE_DOWN];
	mLeft |= pState[SDL_SCANCODE_LEFT];
	mRight |= pState[SDL_SCANCODE_RIGHT];
	mFire |= pState[SDL_SCANCODE_SPACE];
}
