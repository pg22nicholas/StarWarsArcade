#pragma once
#include <vector>
#include "Component.h"
#include "SDL2-2.0.3/include/SDL_scancode.h"
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define FIRE

class ControllerComponent :
    public Component
{
public:
	static std::vector<ControllerComponent*> AllGameControllerComponents;
	ControllerComponent(GameObject* Owner);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void ProccessInput(const uint8_t* pState);

private:
	int mReticleInput;
	bool mFire;
};

