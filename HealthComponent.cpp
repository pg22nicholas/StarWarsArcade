#include "HealthComponent.h"
#include "Game/Private/PlayerManager.h"

HealthComponent::HealthComponent(GameObject* Owner, float health, int team):Component(Owner), mTeam(team), mCurrent(health), mMax(health) {}

ComponentTypes HealthComponent::GetType()
{
	return ComponentTypes::Health;
}

void HealthComponent::TryDamage(float damage, int team)
{
	if (team == mTeam) return;

	mCurrent -= damage;
	if (mCurrent < 0) mCurrent = 0;

	if (mCurrent == 0) {
		mOwningGameObject->Expire();
		PlayerManager::GetManager()->UpdateScore();
	}
}

void HealthComponent::OnHeal(float heal)
{
	mCurrent += heal;
	if (mCurrent > mMax) mCurrent = mMax;
}

bool HealthComponent::CanHit(int team)
{
	return mTeam != team;
}

void HealthComponent::Update(float deltaTime)
{}
