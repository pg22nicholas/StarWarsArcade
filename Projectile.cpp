#include "Projectile.h"

Projectile::Projectile(exVector3 origin, exVector3 heading, ColorTypes color, int team, float damage):GameObject(origin),mHeading(heading),mColor(color),mTeam(team),mDamage(damage) {

	Initialize();
}

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

	if (otherHealth == nullptr) return;
	if (!otherHealth->CanHit(mTeam)) return;
	if (IsExpired()) return;
	Expire();

	otherHealth->TryDamage(mDamage, mTeam);
}
