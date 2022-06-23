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

void PlayerManager::UpdateScore()
{
	++mScore;
}

int PlayerManager::GetScore()
{
	return mScore;
}

PlayerManager::PlayerManager(): mScore(0)
{
	Player* playerPtr = new Player();
	playerPtr->Initialize();
	mPlayer = new GameObjectHandle(playerPtr->GetID());
}

PlayerManager::~PlayerManager()
{
	delete mPlayer;
}

Player* PlayerManager::GetPlayer()
{
	if (mPlayer->IsValid()) {
		return dynamic_cast<Player*>(mPlayer->Get());
	}
	return nullptr;
}

void PlayerManager::Reset()
{
	mScore = 0;
	mElapsedTime = 0;
}

PlayerManager* PlayerManager::sInstance = nullptr;
