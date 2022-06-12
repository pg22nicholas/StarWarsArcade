#include "AttackComponent.h"

AttackComponent::AttackComponent(GameObject* Owner, float damage, int team, std::vector<GameObject*> turrets):Component(Owner), mDamage(damage), mTeam(team), mTurrets(turrets) {}

ComponentTypes AttackComponent::GetType()
{
	return ComponentTypes::Attack;
}

void AttackComponent::Fire(exVector3 target)
{
	for(GameObject* turret: mTurrets) {
		exVector3 turretPosition = turret->GetTransform()->GetLocalPosition();
		exVector3 direction = (target - turretPosition).Normalize();
		new Projectile(turretPosition, direction, ColorTypes::RED);
	}
}
