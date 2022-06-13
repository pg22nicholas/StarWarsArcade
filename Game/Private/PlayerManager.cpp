#include "PlayerManager.h"
#include "Input.h"

// Singleton representing the player position and value
PlayerManager* PlayerManager::GetManager()
{
	if (sInstance == nullptr) {
		sInstance = new PlayerManager();
	}
	return sInstance;
}

PlayerManager::PlayerManager()
{
	mPlayer = new Player();
	mPlayer->Initialize();
}

PlayerManager::~PlayerManager()
{
	delete mPlayer;
}

Player* PlayerManager::GetPlayer()
{
	return mPlayer;
}

PlayerManager* PlayerManager::sInstance = nullptr;
