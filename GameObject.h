#pragma once
#include <vector>
#include "Component.h"
#include "Engine/Public/EngineInterface.h"
#include "Transform.h"

class GameObject
{
public:

	GameObject();
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

protected:
	std::vector<Component*> mComponents;
	Transform* mTransform;

private:

	
};

