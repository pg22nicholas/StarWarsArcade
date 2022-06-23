#include "GameObject.h"
#include "Component.h"
#include "BoxComponent.h"

GameObject::GameObject():mID(GameObjectManager::GetInstance()->GenerateID())
{
	mTransform = new Transform(this);
	AddComponent(mTransform);
	GameObjectManager::GetInstance()->RegisterGameObject(this);
}
GameObject::GameObject(exVector3 startingPosition) :mID(GameObjectManager::GetInstance()->GenerateID())
{
	mTransform = new Transform(this, startingPosition);
	AddComponent(mTransform);
	GameObjectManager::GetInstance()->RegisterGameObject(this);
}
GameObject::GameObject(GameObject* parent) :mID(GameObjectManager::GetInstance()->GenerateID())
{
	mTransform = new Transform(this, parent);
	AddComponent(mTransform);
	GameObjectManager::GetInstance()->RegisterGameObject(this);
}
GameObject::GameObject(exVector3 startingPosition, GameObject* parent) :mID(GameObjectManager::GetInstance()->GenerateID())
{
	mTransform = new Transform(this, startingPosition, parent);
	AddComponent(mTransform);
	GameObjectManager::GetInstance()->RegisterGameObject(this);
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
	GameObjectManager::GetInstance()->DeregisterGameObject(this);
}

// Initializing all the Components
void GameObject::Initialize()
{
	for (Component* IterationComponent : mComponents)
	{
		IterationComponent->Initialize();
	}
}

void GameObject::Update(float deltaTime)
{
	for (auto* component : mComponents) {
		component->Update(deltaTime);
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


int GameObject::GetID()
{
	return mID;
}

void GameObject::OnDestroy()
{
	bIsExpired = true;
	// For overriding in child classes
}


