#include "AttackComponent.h"

AttackComponent::AttackComponent(GameObject* Owner, float damage, int team):Component(Owner), mDamage(damage), mTeam(team) {}

ComponentTypes AttackComponent::GetType()
{
	return ComponentTypes::Attack;
}

void AttackComponent::Fire(exVector3 heading)
{
	heading.Normalize();
}
