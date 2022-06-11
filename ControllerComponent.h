#pragma once
#include <vector>
#include "Component.h"
#include "SDL2-2.0.3/include/SDL_scancode.h"

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

	bool mLeft;
	bool mRight;
	bool mUp;
	bool mDown;
	bool mFire;
};

