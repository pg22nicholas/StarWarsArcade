#include "HealthComponent.h"

HealthComponent::HealthComponent(GameObject* Owner, float health, int team):Component(Owner), mTeam(team), mCurrent(health), mMax(health) {}

ComponentTypes HealthComponent::GetType()
{
	return ComponentTypes::Health;
}

void HealthComponent::OnDamage(float damage)
{
	mCurrent -= damage;
	if (mCurrent < 0) mCurrent = 0;

	if (mCurrent == 0) delete mOwningGameObject;
}

void HealthComponent::OnHeal(float heal)
{
	mCurrent += heal;
	if (mCurrent > mMax) mCurrent = mMax;
}
