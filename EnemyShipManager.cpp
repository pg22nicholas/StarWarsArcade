#include "EnemyShipManager.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Game/Private/Utils.h"
#include "Game/Private/PlayerManager.h"
#include "Bounds.h"

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
		FindValidSpawnLocation();


		PRINT("Spawn new ship");
		// reset counter
		int spawnTime = (rand() % (mMaxTimeSpawn - mMinTimeSpawn)) + mMinTimeSpawn;
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

// based on player position and game bounds, spawn in valid, random location
exVector3 EnemyShipManager::FindValidSpawnLocation()
{
	int spawnTime;

	bool isFoundValue = false;
	exVector3 playerPosition = PlayerManager::GetManager()->GetPlayer()->GetTransform()->GetPosition();
	while (!isFoundValue) {
		spawnTime = rand() % 4;
		switch (spawnTime)
		{
		// Try spawn above player
		case 0:
			if (playerPosition.y <= Bounds::YBounds - mAreaNeededToSpawn)
			{
				PRINT("Spawn down");
				isFoundValue = true;
			}
			else PRINT("Unable to spawn down")
			break;
		// Try spawn below player
		case 1:
			if (playerPosition.y >= -Bounds::YBounds + mAreaNeededToSpawn)
			{
				PRINT("Spawn up");
				isFoundValue = true;
			}
			else PRINT("Unable to spawn up")
			break;
		// Try spawn left of player
		case 2:
			if (playerPosition.x >= -Bounds::xBounds + mAreaNeededToSpawn)
			{
				PRINT("Spawn left");
				isFoundValue = true;
			}
			else PRINT("Unable to spawn left")
			break;
		// Try spawn right of player
		case 3:
			if (playerPosition.x <= Bounds::xBounds - mAreaNeededToSpawn)
			{
				PRINT("Spawn right");
				isFoundValue = true;
			}
			else PRINT("Unable to spawn right")
			break;
		default:
			break;
		}
	}
	return exVector3(0, 0, 0);
	
}

EnemyShipManager* EnemyShipManager::sInstance = nullptr;