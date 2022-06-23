// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "ShipWing.h"

ShipWing::ShipWing(exVector3 position, GameObject* parent):GameObject(position, parent)
{
	Initialize();
}

void ShipWing::Initialize()
{
	AddComponent(new BoxComponent(this, 10, 100));

	GameObject::Initialize();
}
