// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "GameObjectManager.h"

// Game object handle stores a hash of an object, to perform lookups and avoid nullptr error
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
