#pragma once
#include "Player.h"
#include "GameObjectHandle.h"

class PlayerManager
{
public:
	static PlayerManager* GetManager();

	Player* GetPlayer();

private:
	GameObjectHandle* mPlayer;

	PlayerManager();
	~PlayerManager();

	static PlayerManager* sInstance;
};

