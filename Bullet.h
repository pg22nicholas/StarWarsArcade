#pragma once
#include "GameObject.h"
#include "IPhysicsCollisionEvent.h"

class PhysicsComponent;
class Bullet : public GameObject, public IPhysicsCollisionEvent
{
public:

	Bullet();

	virtual void Initialize() override;

	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent);

};
