#include "Reticle.h"

Reticle::Reticle(GameObject* parent): GameObject(Bounds::GetOrigin(), parent) {}

void Reticle::Initialize()
{
	exColor reticleColor;
	reticleColor.mColor[0] = 255;
	reticleColor.mColor[1] = 255;
	reticleColor.mColor[2] = 255;
	reticleColor.mColor[3] = 255;
	AddComponent(new CircleComponent(this, 20, reticleColor, false));

	AddComponent(new PhysicsComponent(this, false, 0, 0, exVector3(), false));
	AddComponent(new ReticleController(this));

	GameObject::Initialize();
}
