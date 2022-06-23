// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "AttackComponent.h"

AttackComponent::AttackComponent(GameObject* Owner, float damage, int team, const std::vector<GameObject*>& turrets):Component(Owner), mDamage(damage), mTeam(team), mTurrets(turrets) {}

ComponentTypes AttackComponent::GetType()
{
	return ComponentTypes::Attack;
}

// Gets direction from own position to target and spawns a projectile
void AttackComponent::Fire(exVector3 target)
{
	for(GameObject* turret: mTurrets) {
		exVector3 turretPosition = turret->GetTransform()->GetLocalPosition();
		exVector3 direction = (target - turretPosition).Normalize();
		new GameObjectHandle((new Projectile(turretPosition, direction, ColorTypes::RED, mTeam, mDamage))->GetID());
	}
}

void AttackComponent::Update(float deltaTime)
{
}
