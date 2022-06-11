#include "Component.h"

Component::Component(GameObject* Owner) :mOwningGameObject(Owner)
{
}

Component::~Component()
{
}

void Component::Initialize()
{
}

void Component::Destroy()
{
}

ComponentTypes Component::GetType()
{
	return ComponentTypes::Empty;
}

GameObject* Component::GetGameObject()
{
	return mOwningGameObject;
}


