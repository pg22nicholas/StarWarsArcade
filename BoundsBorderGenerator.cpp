// Copyright (C) 2022 Nicholas Johnson, All Rights Reserved
#include "BoundsBorderGenerator.h"
#include "Engine/Public/EngineInterface.h"
#include "Bounds.h"
#include <cmath>
#include "GameObject.h"
#include "BoxComponent.h"

void BoundsBorderGenerator::GenerateBounds()
{
	// Bottom left to top left
	GenerateBoundsFromTo(
		exVector3(-Bounds::xBounds - kViewportWidth / 2, -Bounds::YBounds - kViewportHeight / 2, 0), 
		exVector3(-Bounds::xBounds - kViewportWidth / 2, Bounds::YBounds + kViewportHeight/2, 0));

	// Bottom right to top right
	GenerateBoundsFromTo(
		exVector3(Bounds::xBounds + kViewportWidth / 2, -Bounds::YBounds - kViewportHeight / 2, 0),
		exVector3(Bounds::xBounds + kViewportWidth / 2, Bounds::YBounds + kViewportHeight / 2, 0));

	// Bottom left to bottom right
	GenerateBoundsFromTo(
		exVector3(-Bounds::xBounds - kViewportWidth / 2, Bounds::YBounds + kViewportHeight / 2, 0),
		exVector3(Bounds::xBounds + kViewportWidth / 2, Bounds::YBounds + kViewportHeight / 2, 0));
	
	// Top left to top right
	GenerateBoundsFromTo(
		exVector3(-Bounds::xBounds - kViewportWidth / 2, -Bounds::YBounds - kViewportHeight / 2, 0),
		exVector3(Bounds::xBounds + kViewportWidth / 2, -Bounds::YBounds - kViewportHeight / 2, 0));
}

void BoundsBorderGenerator::GenerateBoundsFromTo(exVector3 from, exVector3 to)
{
	float difference = (from.x != to.x) ? from.x - to.x : from.y - to.y;
	exVector3 direction = (to - from).Normalize();
	int numBoxes = (int) std::abs(difference) / mBoxSize;
	for (int i = 0; i <= numBoxes; i++) {
		GameObject* boundsObj = new GameObject(from + direction * i * mBoxSize);
		boundsObj->AddComponent(new BoxComponent(boundsObj, mBoxSize, mBoxSize));
		boundsObj->Initialize();
		new GameObjectHandle(boundsObj->GetID());
	}
}
