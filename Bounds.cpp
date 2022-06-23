// Copyright (C) 2022 Nicholas Johnson, All Rights Reserved
#include "Bounds.h"

const exVector3 Bounds::TopLeft = exVector3(0, 0, 0);
const exVector3 Bounds::TopRight = exVector3(kViewportWidth, 0, 0);
const exVector3 Bounds::BottomLeft = exVector3(0, -kViewportHeight, 0);
const exVector3 Bounds::BottomRight = exVector3(kViewportWidth, -kViewportHeight, 0);