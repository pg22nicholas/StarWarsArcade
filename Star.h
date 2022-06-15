#pragma once
#include "GameObject.h"
#include "CircleComponent.h"

class Star :
    public GameObject
{
public:
	Star(exVector2 flatPosition, GameObject* parent);

	virtual void Initialize() override;
};

