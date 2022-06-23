// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "ReticleController.h"

ReticleController::ReticleController(GameObject* Owner) : ControllerComponent(Owner), mReticleInput(0), bIsFireHeld(false) {}

// Check for arrow keys or space to fire
void ReticleController::ReadInput(const uint8_t* pState)
{
	mReticleInput |= pState[SDL_SCANCODE_UP] << UP_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_DOWN] << DOWN_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_LEFT] << LEFT_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_RIGHT] << RIGHT_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_SPACE] << FIRE_INPUT;

	ParseInput();
}

// Add velocity and/or fire on input
void ReticleController::ParseInput()
{
	PhysicsComponent* physicsComp = mOwningGameObject->FindComponent<PhysicsComponent>(ComponentTypes::Physics);
	Transform* transform = mOwningGameObject->GetTransform();
	exVector3 velocity = exVector3::Zero();

	if ((mReticleInput & 1 << UP_INPUT) != 0) {
		velocity += transform->GetUp();
	}
	else if ((mReticleInput & 1 << DOWN_INPUT) != 0) {
		velocity += transform->GetUp() * -1;
	}

	if ((mReticleInput & 1 << RIGHT_INPUT) != 0) {
		velocity += transform->GetRight();
	}
	else if ((mReticleInput & 1 << LEFT_INPUT) != 0) {
		velocity += transform->GetRight() * -1;
	}

	if ((mReticleInput & 1 << FIRE_INPUT) != 0) {
		if (!bIsFireHeld) {
			bIsFireHeld = true;
			mOwningGameObject->GetTransform()->GetParent()->FindComponent<AttackComponent>(ComponentTypes::Attack)->Fire(GetAimDirection());
		}
	}
	// If fire key is being held down, don't fire multiple times
	else {
		bIsFireHeld = false;
	}

	physicsComp->SetVelocity(velocity.Normalize() * mSpeed);
	mReticleInput = 0;
}

void ReticleController::Update(float deltaTime)
{
	// TODO: Read inputs here
}

// Fake raycast so we target the accurate z-index
exVector3 ReticleController::GetAimDirection()
{
	exVector3 gameObjectPosition = mOwningGameObject->GetTransform()->GetLocalPosition();
	GameObject* RayCastTarget = mOwningGameObject->FindComponent<PhysicsComponent>(ComponentTypes::Physics)->Raycast();
	if (RayCastTarget != nullptr) {
		return exVector3(gameObjectPosition.x, gameObjectPosition.y, RayCastTarget->GetTransform()->GetPosition().z);
	}
	return exVector3(gameObjectPosition.x, gameObjectPosition.y, Bounds::zBounds);
}
