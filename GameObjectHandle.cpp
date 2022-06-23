// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "GameObjectHandle.h"

std::vector<GameObjectHandle*> GameObjectHandle::AllGameObjectHandles;
GameObjectHandle::GameObjectHandle(int hash) : mHash(hash) {
    AllGameObjectHandles.push_back(this);
}

GameObjectHandle::~GameObjectHandle() {
    GameObjectHandle::AllGameObjectHandles.erase(std::remove(GameObjectHandle::AllGameObjectHandles.begin(), GameObjectHandle::AllGameObjectHandles.end(), this), GameObjectHandle::AllGameObjectHandles.end());
}

bool GameObjectHandle::IsValid()
{
    return GameObjectManager::GetInstance()->Exist(Get());
}

GameObject* GameObjectHandle::Get()
{
    return GameObjectManager::GetInstance()->Lookup(mHash);
}