#include "ReticleController.h"

ReticleController::ReticleController(GameObject* Owner) : ControllerComponent(Owner), mReticleInput(0) {}


void ReticleController::ReadInput(const uint8_t* pState)
{
	mReticleInput |= pState[SDL_SCANCODE_UP] << UP_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_DOWN] << DOWN_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_LEFT] << LEFT_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_RIGHT] << RIGHT_INPUT;
	mReticleInput |= pState[SDL_SCANCODE_SPACE] << FIRE_INPUT;

	ParseInput();
}

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
		mOwningGameObject->GetTransform()->GetParent()->FindComponent<AttackComponent>(ComponentTypes::Attack)->Fire(GetAimDirection());
	}

	physicsComp->SetVelocity(velocity.Normalize() * mSpeed);
	mReticleInput = 0;
}

exVector3 ReticleController::GetAimDirection()
{
	exVector3 gameObjectPosition = mOwningGameObject->GetTransform()->GetLocalPosition();
	return exVector3(gameObjectPosition.x, gameObjectPosition.y, Bounds::zBounds).Normalize();
}
