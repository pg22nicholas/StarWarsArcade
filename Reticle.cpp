// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "Reticle.h"
#include "Bounds.h"

Reticle::Reticle(GameObject* parent): GameObject(exVector3::Zero(), parent) {}

// Init with a white circle and a controller to move and fire
void Reticle::Initialize()
{
	exColor reticleColor;
	reticleColor.mColor[0] = 255;
	reticleColor.mColor[1] = 255;
	reticleColor.mColor[2] = 255;
	reticleColor.mColor[3] = 255;
	AddComponent(new CircleComponent(this, 20, reticleColor, StateType::Running, false));

	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3(), false));
	AddComponent(new ReticleController(this));

	GameObject::Initialize();
}
