#include "GameObject.h"
#include "BoxComponent.h"

GameObject::GameObject() 
{
	mTransform = new Transform(this);
	AddComponent(mTransform);
}
GameObject::GameObject(exVector3 startingPosition)
{
	mTransform = new Transform(this, startingPosition);
	AddComponent(mTransform);
}
GameObject::GameObject(GameObject* parent)
{
	mTransform = new Transform(this, parent);
	AddComponent(mTransform);
}
GameObject::GameObject(exVector3 startingPosition, GameObject* parent)
{
	mTransform = new Transform(this, startingPosition, parent);
	AddComponent(mTransform);
}
// Destroyiing all the Componetns linked to Our Game Object.
GameObject::~GameObject()
{
	for (Component* IterationComponent : mComponents)
	{
		if (IterationComponent != nullptr) {
			if (IterationComponent != nullptr && IterationComponent->GetType() == ComponentTypes::Transform) {
				if (Transform* transform = dynamic_cast<Transform*>(IterationComponent)) {
					std::vector<GameObject*> children = transform->GetChildren();
					for (GameObject* child : children) {
						delete child;
					}
				}
			}
		}

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


