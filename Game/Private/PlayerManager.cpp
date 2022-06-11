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


// Read user input and apply to player if applicable
void PlayerManager::ReadInput(int input)
{
	if (input & (int)INPUTS::LEFT) {
		mPlayer->ApplyMovement(MOVEMENT::LEFT);
	}
	else if (input & (int)INPUTS::RIGHT) {
		mPlayer->ApplyMovement(MOVEMENT::RIGHT);
	} else 
		mPlayer->ApplyMovement(MOVEMENT::NONE);
}

Player* PlayerManager::GetPlayer()
{
	return mPlayer;
}

PlayerManager* PlayerManager::sInstance = nullptr;
