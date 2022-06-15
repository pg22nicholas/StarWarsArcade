#pragma once
#include <map>
#include "GameObjectHandle.h"

class GameObject;
class GameObjectManager
{
public:
	static GameObjectManager* GetInstance();
	void RegisterGameObject(GameObject* objectToRegister);
	void DeregisterGameObject(GameObject* objectToDeregister);

	GameObject* Lookup(int hash);
	bool Exist(GameObject* objectToCheck);
	int GenerateID();

private:
	int mGOCounter;
	std::map<int, GameObject*> mGameObjectMap;
	GameObjectManager();
	static GameObjectManager* sInstance;
};

