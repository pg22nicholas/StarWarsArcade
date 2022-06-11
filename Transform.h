#pragma once
#include "Component.h"
#include "Engine/Public/EngineTypes.h"

class Transform :public Component
{

public:
	Transform(GameObject* OwningGameObject);
	Transform(GameObject* OwningGameObject, exVector2 position);

	virtual ComponentTypes GetType() override;

	exVector2 GetPosition(){ return mPosition; }

	void SetPosition(exVector2 position);

private:

	exVector2 mPosition;
};

