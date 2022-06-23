#include "State.h"

StateType RunningState::GetStateType()
{
    return StateType::Running;
}

void RunningState::EnterState()
{
}

void RunningState::ExitState()
{
}

void RunningState::RunState()
{
}

StateType GameOverState::GetStateType()
{
    return StateType::GameOver;
}

void GameOverState::EnterState()
{
}

void GameOverState::ExitState()
{
}

void GameOverState::RunState()
{
}
