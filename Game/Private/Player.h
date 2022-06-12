#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"
#include "ControllerComponent.h"
#include "HealthComponent.h"
#include "Utils.h"
#include "Reticle.h"

class Player : public GameObject
{
public:
	Player();

	virtual void Initialize() override;

	void ApplyMovement(MOVEMENT movement);
	
	Reticle* GetReticle();

private:

	float mMovementSpeed = 100;
	Reticle* mReticle;
};



