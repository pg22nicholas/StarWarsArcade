#pragma once
#include "GameObject.h"
#include "BoxComponent.h"

class ShipWing :
    public GameObject
{
public:
	ShipWing(exVector3 position, GameObject* parent);

	virtual void Initialize() override;
};

