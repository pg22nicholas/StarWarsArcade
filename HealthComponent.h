#pragma once
#include "Component.h"
#include "GameObject.h"

class HealthComponent :
    public Component
{
public:
	HealthComponent(GameObject* Owner, float health, int team);
	virtual ComponentTypes GetType() override;

	void TryDamage(float damage, int team);
	void OnHeal(float heal);
	bool CanHit(int team);

private:
	int mTeam;
	float mCurrent;
	float mMax;
};

