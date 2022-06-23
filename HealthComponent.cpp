// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "HealthComponent.h"
#include "Game/Private/PlayerManager.h"

HealthComponent::HealthComponent(GameObject* Owner, float health, int team):Component(Owner), mTeam(team), mCurrent(health), mMax(health) {}

ComponentTypes HealthComponent::GetType()
{
	return ComponentTypes::Health;
}

// Decreases health and marks for expiry if it reaches 0
void HealthComponent::TryDamage(float damage, int team)
{
	if (team == mTeam) return;

	mCurrent -= damage;
	if (mCurrent < 0) mCurrent = 0;

	if (mCurrent == 0) {
		mOwningGameObject->OnDestroy();
		PlayerManager::GetManager()->UpdateScore();
	}
}

// Never used but could potentially heal the attached object
void HealthComponent::OnHeal(float heal)
{
	mCurrent += heal;
	if (mCurrent > mMax) mCurrent = mMax;
}

// For preventing friendly fire
bool HealthComponent::CanHit(int team)
{
	return mTeam != team;
}

void HealthComponent::Update(float deltaTime)
{}
