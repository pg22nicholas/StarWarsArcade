#include "GameObject.h"
#include "BoxComponent.h"

std::vector<GameObject*> GameObject::AllGameObjects;
GameObject::GameObject() 
{
	mTransform = new Transform(this);
	AddComponent(mTransform);
	AllGameObjects.push_back(this);
}
GameObject::GameObject(exVector3 startingPosition)
{
	mTransform = new Transform(this, startingPosition);
	AddComponent(mTransform);
	AllGameObjects.push_back(this);
}
GameObject::GameObject(GameObject* parent)
{
	mTransform = new Transform(this, parent);
	AddComponent(mTransform);
	AllGameObjects.push_back(this);
}
GameObject::GameObject(exVector3 startingPosition, GameObject* parent)
{
	mTransform = new Transform(this, startingPosition, parent);
	AddComponent(mTransform);
	AllGameObjects.push_back(this);
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
						child->Expire();
					}
				}
			}
		}

		IterationComponent->Destroy();
		delete IterationComponent;
	}
	GameObject::AllGameObjects.erase(std::remove(GameObject::AllGameObjects.begin(), GameObject::AllGameObjects.end(), this), GameObject::AllGameObjects.end());
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

bool GameObject::IsExpired()
{
	return bIsExpired;
}

void GameObject::Expire()
{
	bIsExpired = true;
}


