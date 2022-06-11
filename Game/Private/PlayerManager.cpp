#include "PlayerManager.h"

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
}

PlayerManager::~PlayerManager()
{
	delete mPlayer;
}


// Read user input and apply to player if applicable
void PlayerManager::ReadInput(int input)
{
}

PlayerManager* PlayerManager::sInstance = nullptr;
