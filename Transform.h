#pragma once
#include "Component.h"
#include "Game/Private/exVector3.h"

class Transform :public Component
{

public:
	Transform(GameObject* OwningGameObject);
	Transform(GameObject* OwningGameObject, exVector3 position);
	
	Transform(GameObject* OwningGameObject, GameObject* parentGameObject);
	Transform(GameObject* OwningGameObject, exVector3 position, GameObject* parentGameObject);

	virtual ComponentTypes GetType() override;

	exVector3 GetPosition();
	exVector3 GetLocalPosition();

	void SetPosition(exVector3 position);
	GameObject* GetParent();

private:

	exVector3 mPosition;
	GameObject* mParentGameObject;
};

