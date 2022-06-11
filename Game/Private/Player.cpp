#include "Player.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Utils.h"
#include "Bounds.h"

Player::Player() : GameObject(Bounds::GetOrigin())
{
}

void Player::Initialize()
{
	// Player has no rendering capabilities
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