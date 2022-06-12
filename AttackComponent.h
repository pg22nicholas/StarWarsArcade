#pragma once
#include "Component.h"
#include <Game/Private/exVector3.h>
class AttackComponent :
    public Component
{
public:
	AttackComponent(GameObject* Owner, float damage, int team);
	virtual ComponentTypes GetType() override;

	void Fire(exVector3 heading);

private:
	int mTeam;
	float mDamage;
};

