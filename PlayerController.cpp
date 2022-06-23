// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "PlayerController.h"
#include "Bounds.h"
#include <algorithm>

PlayerController::PlayerController(GameObject* Owner) : ControllerComponent (Owner), mPlayerInput(0) {}

// Checks if WASD has been pressed
void PlayerController::ReadInput(const uint8_t* pState)
{
	mPlayerInput |= pState[SDL_SCANCODE_W] << UP_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_S] << DOWN_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_A] << LEFT_INPUT;
	mPlayerInput |= pState[SDL_SCANCODE_D] << RIGHT_INPUT;

	ParseInput();
}

// Adds velocity to the player based on input
void PlayerController::ParseInput()
{
	exVector3 position = mOwningGameObject->GetTransform()->GetPosition();
	if (position.y > Bounds::YBounds)
		mOwningGameObject->GetTransform()->SetPosition(exVector3(position.x, Bounds::YBounds, position.z));
	if (position.y < -Bounds::YBounds) 
		mOwningGameObject->GetTransform()->SetPosition(exVector3(position.x, -Bounds::YBounds, position.z));
	if (position.x > Bounds::xBounds) 
		mOwningGameObject->GetTransform()->SetPosition(exVector3(Bounds::xBounds, position.y, position.z));
	if (position.x < -Bounds::xBounds) 
		mOwningGameObject->GetTransform()->SetPosition(exVector3(-Bounds::xBounds, position.y, position.z));

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

void PlayerController::Update(float deltaTime)
{
	// TODO: read inputs from here
}
