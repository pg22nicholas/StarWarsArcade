#pragma once
#include <vector>
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "PhysicsComponent.h"
#include "Game/Private/exVector3.h"

class TransformComponent;
class BoxComponent;
class CircleComponent;

class PhysicsComponent : public Component
{
public:

	PhysicsComponent(GameObject* OwningGameObject, bool gravityEnabled = false, float gravityScale = 1.0f, float mass = 0.0f, exVector3 Velocity = exVector3(), bool bIsCollisionEnabled = true);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	bool IsColliding(PhysicsComponent* OtherPhysicsComponent);

	virtual void Update(float pDeltaTime);

private:

	bool bGravityEnabled;
	float mGravityScale;
	float mMass;

	exVector3 mVelocity;
	bool bIsCollisionEnabled;

	bool CircleSquareCollisionCheck(CircleComponent* circle, BoxComponent* box);

public:

	//All Physics Components
	static std::vector<PhysicsComponent*> mAllPhysicsComponents;

	// Stores all the Collision Event Handlers
	std::vector<IPhysicsCollisionEvent*> mCollisionEvents;

	void AddColissionEventLitsner(IPhysicsCollisionEvent* pEvent);
};

