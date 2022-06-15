#pragma once
#include <vector>
#include "GameObjectHandle.h"
class exVector3;

class EnemyShipManager
{
public:
	static EnemyShipManager* GetManager();

	void Update(float deltaTime);

private:

	std::vector<GameObjectHandle*> mEnemyShips;
	EnemyShipManager();
	~EnemyShipManager();

	const int mMinTimeSpawn = 1;
	const int mMaxTimeSpawn = 5;
	const float mAreaNeededToSpawn = 50;

	float mDurationRemaining = 0;

	exVector3 FindValidSpawnLocation();
	int GetRandBetweenValues(int a, int b);

	static EnemyShipManager* sInstance;
};

