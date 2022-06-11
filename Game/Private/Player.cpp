#include "Player.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Utils.h"

Player::Player() : GameObject()
{
}

void Player::Initialize()
{
	// Player has no rendering capabilities
	mTransform->SetPosition(exVector3(0, 0, 0));
	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3()));
	// TODO: health, and stat components

	GameObject::Initialize();
}

void Player::ApplyMovement(MOVEMENT movement)
{
	switch (movement)
	{
	case MOVEMENT::LEFT:
		FindComponent<PhysicsComponent>(ComponentTypes::Physics)->SetVelocity(exVector3(-mMovementSpeed, 0, 0));
		break;
	case MOVEMENT::RIGHT:
		FindComponent<PhysicsComponent>(ComponentTypes::Physics)->SetVelocity(exVector3(mMovementSpeed, 0, 0));
		break;
	default:
		FindComponent<PhysicsComponent>(ComponentTypes::Physics)->SetVelocity(exVector3(0, 0, 0));
		break;
	}
}
