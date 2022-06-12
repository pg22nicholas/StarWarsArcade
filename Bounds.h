#pragma once
#include "Engine/Public/EngineInterface.h"
#include "Game/Private/exVector3.h"

// Holds position bounds of GameObjects and simple related logic
class Bounds {

public:
	static constexpr float centerX = (float) kViewportWidth / 2;
	static constexpr float centerY = (float) kViewportHeight / 2;
	static const int zBounds = 100;	// The distance on object can travel in z-direction before dissappearing
	static const int xBounds = 100;	// distance the player/camera can travel left/right

	// get the percent size of the gameObject based on its z-position, with a min of 0, max of zBounds
	static float zSizePercentage(float z) {
		return 1 - (z / zBounds);
	}

	static exVector3 GetOrigin() {
		return exVector3(centerX, centerY, 0);
	}

	static const exVector3 TopLeft;
	static const exVector3 TopRight;
	static const exVector3 BottomLeft;
	static const exVector3 BottomRight;
};