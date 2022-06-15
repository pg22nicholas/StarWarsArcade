#pragma once
#include "GameObject.h"
#include "GameObjectManager.h"

class GameObjectHandle
{
public:

	static std::vector<GameObjectHandle*> AllGameObjectHandles;
	GameObjectHandle(int hash);
	~GameObjectHandle();
	int mHash;

	bool IsValid();

	GameObject* Get();

};
