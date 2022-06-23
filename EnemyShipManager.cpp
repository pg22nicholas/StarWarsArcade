#include "EnemyShipManager.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Game/Private/Utils.h"
#include "Game/Private/PlayerManager.h"
#include "Bounds.h"
#include "EnemyShip.h"

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
		exVector3 spawnLocation = FindValidSpawnLocation();
		
		// Send enemy ship in directly roughly towards player
		exVector3 vecToPlayer = ((PlayerManager::GetManager()->GetPlayer()->GetTransform()->GetPosition() - spawnLocation) + exVector3(0, 0, 30))
									.RotateAroundZ((float)(rand() & (mRotationNoise * 2) - mRotationNoise))
									.Normalize() * 100;

		new GameObjectHandle((new EnemyShip(shipID++, spawnLocation, vecToPlayer))->GetID());

		PRINT("Spawn new ship");
		// reset counter
		int spawnTime = (rand() % (mMaxTimeSpawn - mMinTimeSpawn)) + mMinTimeSpawn;
		mDurationRemaining = (float)spawnTime;
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

	exVector3 playerPosition = PlayerManager::GetManager()->GetPlayer()->GetTransform()->GetPosition();
	while (true) {
		spawnTime = rand() % 4;
		switch (spawnTime)
		{
		// Try spawn below
		case 0:
			if (playerPosition.y <= Bounds::YBounds - mAreaNeededToSpawn)
			{
				int randY = GetRandBetweenValues((int)playerPosition.y + kViewportHeight / 2, Bounds::YBounds + kViewportHeight / 2);
				int randX = GetRandBetweenValues(-Bounds::xBounds - kViewportWidth / 2, Bounds::xBounds + kViewportWidth / 2);
				return exVector3((float)randX, (float)randY, 0);
			}
			break;
		// Try spawn above player
		case 1:
			if (playerPosition.y >= -Bounds::YBounds + mAreaNeededToSpawn)
			{
				int randY = GetRandBetweenValues((int)playerPosition.y - kViewportHeight / 2, -Bounds::YBounds - kViewportHeight / 2);
				int randX = GetRandBetweenValues(-Bounds::xBounds - kViewportWidth / 2, Bounds::xBounds + kViewportWidth / 2);
				return exVector3((float)randX, (float)randY, 0);
			}
			break;
		// Try spawn left of player
		case 2:
			if (playerPosition.x >= -Bounds::xBounds + mAreaNeededToSpawn)
			{
				int randY = GetRandBetweenValues(-Bounds::YBounds - kViewportHeight / 2, Bounds::YBounds + kViewportHeight / 2);
				int randX = GetRandBetweenValues((int)playerPosition.x - kViewportWidth / 2, -Bounds::xBounds - kViewportWidth / 2);
				return exVector3((float)randX, (float)randY, 0);
			}
			break;
		// Try spawn right of player
		case 3:
			if (playerPosition.x <= Bounds::xBounds - mAreaNeededToSpawn)
			{
				int randY = GetRandBetweenValues(-Bounds::YBounds - kViewportHeight / 2, Bounds::YBounds + kViewportHeight / 2);
				int randX = GetRandBetweenValues((int)playerPosition.x + kViewportWidth / 2, Bounds::xBounds + kViewportWidth / 2);
				return exVector3((float)randX, (float)randY, 0);
			}
			break;
		default:
			break;
		}
	}
}

int EnemyShipManager::GetRandBetweenValues(int a, int b)
{
	return rand() % std::abs(b - a) + min(a, b);
}

EnemyShipManager* EnemyShipManager::sInstance = nullptr;