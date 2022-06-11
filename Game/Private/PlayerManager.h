#pragma once
#include "Player.h"

class PlayerManager
{
public:
	static PlayerManager* GetManager();

	void ReadInput(int input);

private:
	Player* mPlayer;

	PlayerManager();
	~PlayerManager();

	static PlayerManager* sInstance;
};

