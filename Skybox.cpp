#include "Skybox.h"

Skybox::Skybox():GameObject(exVector3(0, 0, 0)) {
	Initialize();
}

void Skybox::Initialize()
{
	BoxComponent* skybox = new BoxComponent(this, kViewportWidth + 2 * Bounds::xBounds, kViewportHeight + 2 * Bounds::YBounds);
	skybox->SetColor(ColorTypes::BLACK);
	AddComponent(skybox);

	GameObject::Initialize();
}
