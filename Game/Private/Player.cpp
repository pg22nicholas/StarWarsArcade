#include "Player.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/Utils.h"
#include "Bounds.h"
#include "PlayerController.h"
#include "GameObjectHandle.h"
#include "Timer.h"

Player::Player() : GameObject(exVector3::Zero())
{
	Reticle* rectile = new Reticle(this);
	mReticle = new GameObjectHandle(rectile->GetID());
	rectile->Initialize();

	new GameObjectHandle((new Timer(this, 60))->GetID());
}

void Player::Initialize()
{
	// Player has no rendering capabilities
	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3()));
	AddComponent(new PlayerController(this));

	std::vector<GameObject*> turrets;
	turrets.push_back(new GameObject(exVector3(-Bounds::centerX, Bounds::centerY, 0), this));
	turrets.push_back(new GameObject(exVector3(Bounds::centerX, Bounds::centerY, 0), this));
	AddComponent(new AttackComponent(this, 1, 0, turrets));
	AddComponent(new HealthComponent(this, 10, 0));
	// TODO: health, and stat components

	GameObject::Initialize();
}
