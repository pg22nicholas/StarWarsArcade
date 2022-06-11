#pragma once

class Bounds {

public:
	static const int zBounds = 100;	// The distance on object can travel in z-direction before dissappearing
	static const int xBounds = 100;	// distance the player/camera can travel left/right

	// get the percent size of the gameObject based on its z-position, with a min of 0, max of zBounds
	static float zSizePercentage(float z) {
		return 1 - (z / zBounds);
	}
};
