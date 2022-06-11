#include "GameObject.h"
#include "BoxComponent.h"

GameObject::GameObject() 
{
	mTransform = new Transform(this);
	AddComponent(mTransform);
}
// Destroyiing all the Componetns linked to Our Game Object.
GameObject::~GameObject()
{
	for (Component* IterationComponent : mComponents)
	{
		IterationComponent->Destroy();
		delete IterationComponent;
	}
}

// Initializing all the Components
void GameObject::Initialize()
{
	for (Component* IterationComponent : mComponents)
	{
		IterationComponent->Initialize();
	}
}

void GameObject::AddComponent(Component* ComponentToAdd)
{
	mComponents.push_back(ComponentToAdd);
}


