#include "PlayerController.h"

PlayerController::PlayerController(GameObject* Owner) : ControllerComponent (Owner), mPlayerInput(0) {}

void PlayerController::ReadInput(const uint8_t* pState)
{
	mPlayerInput |= pState[SDL_SCANCODE_W] << UP_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_S] << DOWN_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_A] << LEFT_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_D] << RIGHT_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_SPACE] << FIRE_INPUT;

	ParseInput();
}

void PlayerController::ParseInput()
{
	PhysicsComponent* physicsComp = mOwningGameObject->FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	Transform* transform = mOwningGameObject->GetTransform();
	exVector3 velocity = exVector3::Zero();

	if ((mPlayerInput & 1 << UP_INPUT) != 0) {
		velocity += transform->GetUp();
	}
	else if ((mPlayerInput & 1 << DOWN_INPUT) != 0) {
		velocity += transform->GetUp() * -1;
	}

	if ((mPlayerInput & 1 << RIGHT_INPUT) != 0) {
		velocity += transform->GetRight();
	}
	else if ((mPlayerInput & 1 << LEFT_INPUT) != 0) {
		velocity += transform->GetRight() * -1;
	}

	physicsComp->SetVelocity(velocity.Normalize() * mSpeed);
	mPlayerInput = 0;
}
