#pragma once
#include "ControllerComponent.h"
#include "PhysicsComponent.h"
#include "SDL2-2.0.3/include/SDL_scancode.h"
#define LEFT_INPUT 0
#define RIGHT_INPUT 1
#define UP_INPUT 2
#define DOWN_INPUT 3
#define FIRE_INPUT 4

class PlayerController :
    public ControllerComponent
{
public:
	PlayerController(GameObject* Owner);

	virtual void ReadInput(const uint8_t* pState) override;
	virtual void ParseInput() override;

private:
	int mPlayerInput;
	float mSpeed = 100;
};

