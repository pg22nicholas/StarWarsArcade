#pragma once


class PhysicsComponent;

class IPhysicsCollisionEvent
{

public:
	virtual void OnCollision(PhysicsComponent* pCurrentComponent, PhysicsComponent* pOtherComponent) = 0;
};


