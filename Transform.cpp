#include "Transform.h"
#include "GameObject.h"

Transform::Transform(GameObject* OwningGameObject) :Component(OwningGameObject), mPosition(exVector3(1, 1, 1)), mParentGameObject(nullptr)
{ 
}

Transform::Transform(GameObject* OwningGameObject, exVector3 position) : Component(OwningGameObject), mPosition(position), mParentGameObject(nullptr)
{
}

Transform::Transform(GameObject* OwningGameObject, GameObject* parentGameObject) : Component(OwningGameObject), mParentGameObject(parentGameObject)
{
	mParentGameObject->GetTransform()->AddChild(OwningGameObject);
}

Transform::Transform(GameObject* OwningGameObject, exVector3 position, GameObject* parentGameObject) : Component(OwningGameObject), mPosition(position), mParentGameObject(parentGameObject)
{
	mParentGameObject->GetTransform()->AddChild(OwningGameObject);
}

ComponentTypes Transform::GetType()
{
    return ComponentTypes::Transform;
}

void Transform::SetPosition(exVector3 position)
{
    mPosition = position;
}

GameObject* Transform::GetParent()
{
	return mParentGameObject;
}

void Transform::AddChild(GameObject* child)
{
	mChildrenGameObjects.push_back(child);
}

std::vector<GameObject*> Transform::GetChildren()
{
	return mChildrenGameObjects;
}

void Transform::Update(float deltaTime) {}

exVector3 Transform::GetPosition() { return mPosition; }
exVector3 Transform::GetLocalPosition() {

	// TODO: Use handlers for gameObject references
	if (mParentGameObject == nullptr) return mPosition;
	exVector3 localVec = mParentGameObject->GetTransform()->GetLocalPosition() + mPosition;
	return localVec;
}

exVector3 Transform::GetForward()
{
	return mForward;
}

exVector3 Transform::GetUp()
{
	return mUp;
}

exVector3 Transform::GetRight()
{
	return exVector3::Cross(mForward, mUp);
}
