#pragma once
#include "Component.h"

#include "Game/Private/exVector3.h"

class Transform :public Component
{

public:
	Transform(GameObject* OwningGameObject);
	Transform(GameObject* OwningGameObject, exVector3 position);

	virtual ComponentTypes GetType() override;

	exVector3 GetPosition(){ return mPosition; }

	void SetPosition(exVector3 position);

private:

	exVector3 mPosition;
};

