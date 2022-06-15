#include "GameObjectManager.h"

// Singleton manager to track hashmap of existing gameobjects 
GameObjectManager* GameObjectManager::sInstance = nullptr;
GameObjectManager* GameObjectManager::GetInstance()
{
    if (sInstance == nullptr) sInstance = new GameObjectManager();
    return sInstance;
}

// Register GameObjects at construction
void GameObjectManager::RegisterGameObject(GameObject* objectToRegister)
{
    int index = objectToRegister->GetID();
    mGameObjectMap.emplace(index, objectToRegister);
}

// Deregister gameobjects  and destruction
void GameObjectManager::DeregisterGameObject(GameObject* objectToDeregister)
{
    mGameObjectMap.erase(objectToDeregister->GetID());
}

// Find object from Hash
GameObject* GameObjectManager::Lookup(int hash)
{
    auto iterator = mGameObjectMap.find(hash);
    if (iterator != mGameObjectMap.end()) return iterator->second;
    return nullptr;
}

// Check if an object exists in the map
bool GameObjectManager::Exist(GameObject* objectToCheck)
{
    if (objectToCheck == nullptr) return false;
    return Lookup(objectToCheck->GetID()) == objectToCheck;
}

int GameObjectManager::GenerateID()
{
    return mGOCounter++;
}

GameObjectManager::GameObjectManager() {
    mGOCounter = 0;
}