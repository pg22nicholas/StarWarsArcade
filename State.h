// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#pragma once
#include "GameObjectHandle.h"
#include "Game/Private/Utils.h"

// Interface implemented by running and game over states
class State
{
public:
	virtual StateType GetStateType() = 0;
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void RunState(float deltaT) = 0;
};

class RunningState : public State
{
public:
	virtual StateType GetStateType() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void RunState(float deltaT) override;
};

class GameOverState : public State
{
public:
	virtual StateType GetStateType() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void RunState(float deltaT) override;
};

