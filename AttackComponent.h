#pragma once
#include "Component.h"
#include "Projectile.h"
#include <Game/Private/exVector3.h>
class AttackComponent :
    public Component
{
public:
	AttackComponent(GameObject* Owner, float damage, int team, std::vector<GameObject*> turrets);
	virtual ComponentTypes GetType() override;

	void Fire(exVector3 heading);

private:
	int mTeam;
	float mDamage;
	std::vector<GameObject*> mTurrets;
};

