#pragma once
#include "Player.h"

class PlayerManager
{
public:
	static PlayerManager* GetManager();

	Player* GetPlayer();

private:
	Player* mPlayer;

	PlayerManager();
	~PlayerManager();

	static PlayerManager* sInstance;
};

