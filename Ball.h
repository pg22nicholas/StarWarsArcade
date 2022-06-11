#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Ball : public GameObject, public IPhysicsCollisionEvent
{
public:

	Ball();

	virtual void Initialize() override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

};

