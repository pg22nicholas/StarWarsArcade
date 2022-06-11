#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Box : public GameObject, public IPhysicsCollisionEvent
{
public:

	Box();

	virtual void Initialize() override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

};

