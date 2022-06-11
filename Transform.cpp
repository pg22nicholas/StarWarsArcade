#include "Transform.h"


Transform::Transform(GameObject* OwningGameObject) :Component(OwningGameObject)
{
    mPosition = exVector2();
    mPosition.x = 0;
    mPosition.y = 0;
}

Transform::Transform(GameObject* OwningGameObject, exVector2 position) : Component(OwningGameObject), mPosition(position)
{
}

ComponentTypes Transform::GetType()
{
    return ComponentTypes::Transform;
}

void Transform::SetPosition(exVector2 position)
{
    mPosition = position;
}
