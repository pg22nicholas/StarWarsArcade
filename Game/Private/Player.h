#pragma once
#include "GameObject.h"
#include "PhysicsComponent.h"

enum class MOVEMENT {
	LEFT,
	RIGHT
};

class Player : public GameObject
{
public:
	Player();

	virtual void Initialize() override;

	void ApplyMovement(MOVEMENT movement);
	
	

private:

	float mMovementSpeed = 20;
};



