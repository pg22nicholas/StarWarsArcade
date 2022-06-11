#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Ship : public GameObject, public IPhysicsCollisionEvent
{
public:

	Ship();

	virtual void Initialize() override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

};
