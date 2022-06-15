#pragma once
#include <vector>
#include "GameObjectHandle.h"

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

	float mDurationRemaining = 0;

	static EnemyShipManager* sInstance;
};

