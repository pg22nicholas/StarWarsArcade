#include "EnemyShipManager.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Game/Private/Utils.h"

// Singleton representing the player position and value
EnemyShipManager* EnemyShipManager::GetManager()
{
	if (sInstance == nullptr) {
		sInstance = new EnemyShipManager();
	}
	return sInstance;
}

void EnemyShipManager::Update(float deltaTime)
{
	mDurationRemaining -= deltaTime;

	// Spawn an enemy ship
	if (mDurationRemaining <= 0) {
		// TODO: Spawn new ship 
		PRINT("Spawn new ship");
		// reset counter
		int spawnTime = (rand() % (mMaxTimeSpawn - mMinTimeSpawn)) + mMinTimeSpawn + 1;
		mDurationRemaining = spawnTime;
	}
}

EnemyShipManager::EnemyShipManager()
{
	srand(time(NULL));
}

EnemyShipManager::~EnemyShipManager()
{
}

EnemyShipManager* EnemyShipManager::sInstance = nullptr;