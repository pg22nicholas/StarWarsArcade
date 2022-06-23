#pragma once
enum class StateType {
	Running,
	GameOver,
};

class State
{
public:
	virtual StateType GetStateType() = 0;
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void RunState() = 0;
};

class RunningState : public State
{
public:
	virtual StateType GetStateType() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void RunState() override;
};

class GameOverState : public State
{
public:
	virtual StateType GetStateType() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual void RunState() override;
};

