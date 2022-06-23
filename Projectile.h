// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "CircleComponent.h"
#include "HealthComponent.h"

// Collidable GO that deals damage to objects not on the same team
class Projectile :
    public GameObject, IPhysicsCollisionEvent
{
public:
	Projectile(exVector3 origin, exVector3 heading, ColorTypes color, int team, float damage);

	virtual void Initialize() override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent) override;

private:
	exVector3 mHeading;
	ColorTypes mColor;
	float mSpeed = 500;
	float mRadius = 10;
	float mDamage;
	int mTeam;
};

