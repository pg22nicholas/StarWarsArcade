#pragma once
#include "Game/Private/exVector3.h"

class BoundsBorderGenerator
{
public:
	static void GenerateBounds();

private:
	static void GenerateBoundsFromTo(exVector3 from, exVector3 to);

	static const int mBoxSize = 50;
};

