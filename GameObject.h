#pragma once
#include <vector>
#include "Component.h"
#include "Engine/Public/EngineInterface.h"
#include "Transform.h"

class GameObject
{
public:
	static std::vector<GameObject*> AllGameObjects;
	GameObject();
	GameObject(exVector3 startingPosition);
	GameObject(GameObject* parent);
	GameObject(exVector3 startingPosition, GameObject* parent);
	~GameObject();

	virtual void Initialize();

	void AddComponent(Component* ComponentToAdd);

	template<typename T>
	T* FindComponent(ComponentTypes eType)
	{
		for (Component* ComponentIterator : mComponents)
		{
			if (ComponentIterator->GetType() == eType)
			{
				return (T*)ComponentIterator;
			}
		}
		return nullptr;
	}

	Transform* GetTransform()
	{
		return mTransform;
	}

	bool IsExpired();
	void Expire();

protected:
	std::vector<Component*> mComponents;
	Transform* mTransform;
	bool bIsExpired = false;

private:

	
};

