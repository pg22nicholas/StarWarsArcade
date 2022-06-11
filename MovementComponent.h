#pragma once
#include "Component.h"
class MovementComponent :
    public Component
{
public:
	MovementComponent(GameObject* Owner);
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual ComponentTypes GetType() override;

};

