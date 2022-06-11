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
}

Transform::Transform(GameObject* OwningGameObject, exVector3 position, GameObject* parentGameObject) : Component(OwningGameObject), mPosition(exVector3(1, 1, 1)), mParentGameObject(parentGameObject)
{
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

exVector3 Transform::GetPosition() { return mPosition; }
exVector3 Transform::GetLocalPosition() {

	// TODO: Use handlers for gameObject references
	if (mParentGameObject == nullptr) return mPosition;
	exVector3 localVec = mParentGameObject->GetTransform()->GetLocalPosition() + mPosition;
	return localVec;
}
