// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "Skybox.h"
#include "Star.h"

Skybox::Skybox():GameObject(exVector3(0, 0, 0)) {
	Initialize();
}

// Generate stars at random positions within the bounds
void Skybox::Initialize()
{
	float width = kViewportWidth + 2 * Bounds::xBounds;
	float height = kViewportHeight + 2 * Bounds::YBounds;
	BoxComponent* skybox = new BoxComponent(this, kViewportWidth + 2 * Bounds::xBounds, kViewportHeight + 2 * Bounds::YBounds, StateType::Running, true);
	skybox->SetColor(ColorTypes::BLACK);
	AddComponent(skybox);

	exVector2 spawnableArea;
	spawnableArea.x = width;// -2 * Star::kSize;
	spawnableArea.y = height;// -2 * Star::kSize;

	for (int i = 0; i < kNumStars; i++) {
		exVector2 position;
		position.x = (rand() % (int)spawnableArea.x) - (spawnableArea.x / 2);
		position.y = (rand() % (int)spawnableArea.y) - (spawnableArea.y / 2);
		new GameObjectHandle((new Star(position, this))->GetID());
	}

	GameObject::Initialize();
}
