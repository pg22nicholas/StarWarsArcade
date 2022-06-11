#pragma once
#include "Component.h"
class MovementComponent :
    public Component
{
	MovementComponent(GameObject* Owner);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

};

