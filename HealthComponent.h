#pragma once
#include "Component.h"

class HealthComponent :
    public Component
{
public:
	HealthComponent(GameObject* Owner, float health, int team);
	virtual ComponentTypes GetType() override;

	void OnDamage(float damage);
	void OnHeal(float heal);

private:
	int mTeam;
	float mCurrent;
	float mMax;
};

