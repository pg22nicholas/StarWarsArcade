#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "CircleComponent.h"
#
class Projectile :
    public GameObject
{
public:
	Projectile(exVector3 origin, exVector3 heading, ColorTypes color);

	virtual void Initialize() override;

private:
	exVector3 mHeading;
	ColorTypes mColor;
	float mSpeed = 500;
	float mRadius = 50;
};

