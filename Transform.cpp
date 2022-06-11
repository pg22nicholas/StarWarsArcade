#include "Transform.h"



Transform::Transform(GameObject* OwningGameObject) :Component(OwningGameObject)
{ 
    mPosition = exVector3(1, 1, 1);
}

Transform::Transform(GameObject* OwningGameObject, exVector3 position) : Component(OwningGameObject), mPosition(position)
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
