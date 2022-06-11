#include "ControllerComponent.h"

std::vector<ControllerComponent*> ControllerComponent::AllGameControllerComponents;

ControllerComponent::ControllerComponent(GameObject* Owner) : Component(Owner), mReticleInput(0), mFire(false) {}

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
	mReticleInput |= pState[SDL_SCANCODE_UP] << UP;
	mReticleInput |= pState[SDL_SCANCODE_DOWN] << DOWN;
	mReticleInput |= pState[SDL_SCANCODE_LEFT] << LEFT;
	mReticleInput |= pState[SDL_SCANCODE_RIGHT] << RIGHT;

	mFire |= pState[SDL_SCANCODE_SPACE];
}
