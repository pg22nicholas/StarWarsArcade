// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "CircleComponent.h"

// GO for each star
class Star :
    public GameObject
{
public:
	Star(exVector2 flatPosition, GameObject* parent);

	virtual void Initialize() override;

	static const float kSize;
};

