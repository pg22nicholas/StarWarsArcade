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

void ControllerComponent::ReadInput(const uint8_t* pState)
{
	mReticleInput |= pState[SDL_SCANCODE_UP] << UP_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_DOWN] << DOWN_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_LEFT] << LEFT_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_RIGHT] << RIGHT_INPUT;

	SetReticleMovement();
	//mFire |= pState[SDL_SCANCODE_SPACE];


}

void ControllerComponent::SetReticleMovement()
{
	PhysicsComponent* physicsComp = mOwningGameObject->FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	Transform* tranform = mOwningGameObject->GetTransform();
	exVector3 velocity;

	if (mReticleInput == 1 << UP_INPUT) {
		velocity += tranform->GetUp();
	}
	else if (mReticleInput == 1 << DOWN_INPUT) {
		velocity += tranform->GetUp() * -1;
	}
	if (mReticleInput == 1 << RIGHT_INPUT) {
		velocity += tranform->GetRight();
	}
	else if (mReticleInput == 1 << LEFT_INPUT) {
		velocity += tranform->GetRight() * -1;
	}
	if (mReticleInput != 0) {
		physicsComp->SetVelocity(velocity.Normalize() * mReticleSpeed);
	}
}
