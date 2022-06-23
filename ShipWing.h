// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "BoxComponent.h"

// Unused component to give ships tie fighter style wings
class ShipWing :
    public GameObject
{
public:
	ShipWing(exVector3 position, GameObject* parent);

	virtual void Initialize() override;
};

