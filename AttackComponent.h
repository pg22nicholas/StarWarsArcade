// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved

#pragma once
#include "Component.h"
#include "Projectile.h"
#include <Game/Private/exVector3.h>
class AttackComponent :
    public Component
{
public:
	AttackComponent(GameObject* Owner, float damage, int team, const std::vector<GameObject*> &turrets);
	virtual ComponentTypes GetType() override;

	void Fire(exVector3 heading);
	virtual void Update(float deltaTime) override;

private:
	int mTeam; // Spawning object's team to prevent friendly fire
	float mDamage; // Damage dealt by projectile
	std::vector<GameObject*> mTurrets; // Location(s) from which projectiles get spawned
};

