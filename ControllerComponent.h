#pragma once
#include <vector>
#include "Component.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "SDL2-2.0.3/include/SDL_scancode.h"
#define LEFT_INPUT 0
#define RIGHT_INPUT 1
#define UP_INPUT 2
#define DOWN_INPUT 3

class ControllerComponent :
    public Component
{
public:
	static std::vector<ControllerComponent*> AllGameControllerComponents;
	ControllerComponent(GameObject* Owner);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void ReadInput(const uint8_t* pState);
	void SetReticleMovement();

private:
	int mReticleInput;
	float mReticleSpeed = 20;
	bool mFire;
};

