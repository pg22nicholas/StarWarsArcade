#pragma once
#include <vector>
#include "GameObject.h"
class ControllerComponent : public Component
{
public:
	static std::vector<ControllerComponent*> AllGameControllerComponents;
	ControllerComponent(GameObject* Owner);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

	virtual void ReadInput(const uint8_t* pState) = 0;
	virtual void SetReticleMovement() = 0;
};

