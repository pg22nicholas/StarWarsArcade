// Copyright (C) 2022 Nicholas Johnson, All Rights Reserved
#pragma once
#include "Player.h"
#include "GameObjectHandle.h"

class PlayerManager
{
public:
	static PlayerManager* GetManager();
	void UpdateScore();
	int GetScore();
	Player* GetPlayer();
	void Reset();

	float mElapsedTime;

private:
	GameObjectHandle* mPlayer;

	PlayerManager();
	~PlayerManager();

	static PlayerManager* sInstance;
	int mScore;
};

