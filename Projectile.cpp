#include "Projectile.h"

Projectile::Projectile(exVector3 origin, exVector3 heading, ColorTypes color):GameObject(origin),mHeading(heading),mColor(color) {
}

void Projectile::Initialize()
{
	AddComponent(new PhysicsComponent(this, false, 0, 0, mHeading * mSpeed));
	CircleComponent* circleComp = new CircleComponent(this, mRadius);
	circleComp->SetColor(mColor);
	AddComponent(circleComp);
}
