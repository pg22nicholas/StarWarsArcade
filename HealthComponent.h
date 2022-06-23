// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "Component.h"
#include "GameObject.h"

// Health component tracks current and max health, and allows the object to take damage or heal
class HealthComponent :
    public Component
{
public:
	HealthComponent(GameObject* Owner, float health, int team);
	virtual ComponentTypes GetType() override;

	void TryDamage(float damage, int team);
	void OnHeal(float heal);
	bool CanHit(int team);
	virtual void Update(float deltaTime) override;

private:
	int mTeam;
	float mCurrent;
	float mMax;
};

