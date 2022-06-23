// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "Projectile.h"

Projectile::Projectile(exVector3 origin, exVector3 heading, ColorTypes color, int team, float damage):GameObject(origin),mHeading(heading),mColor(color),mTeam(team),mDamage(damage) {

	Initialize();
}

// Set velocity from it's speed and heading provided through constructor
void Projectile::Initialize()
{
	PhysicsComponent* physicsComponent = new PhysicsComponent(this, false, 0, 0, mHeading * mSpeed);
	physicsComponent->AddColissionEventLitsner(this);
	AddComponent(physicsComponent);

	CircleComponent* circleComp = new CircleComponent(this, mRadius);
	circleComp->SetColor(mColor);
	AddComponent(circleComp);

	GameObject::Initialize();
}

void Projectile::OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent)
{
	if (FindComponent<PhysicsComponent>(ComponentTypes::Physics) != pCurrentComponent) return;
	HealthComponent* otherHealth = pOtherComponent->GetGameObject()->FindComponent<HealthComponent>(ComponentTypes::Health);

	// Check enemy has health component
	if (otherHealth == nullptr) return;

	// Check enemy is on a different team
	if (!otherHealth->CanHit(mTeam)) return;

	//Check if expired, i.e, has already hit something
	if (IsExpired()) return;
	OnDestroy();

	// Deal damage
	otherHealth->TryDamage(mDamage, mTeam);
}
