// Copyright (C) 2022 Shatrujit Aditya Kumar, All Rights Reserved
#include "State.h"
#include "EnemyShipManager.h"
#include "Game/Private/PlayerManager.h"

// Handle game state, between running and the game over screen
StateType RunningState::GetStateType()
{
    return StateType::Running;
}

void RunningState::EnterState()
{
	PlayerManager::GetManager()->Reset();
}

void RunningState::ExitState()
{
}

void RunningState::RunState(float deltaT)
{
	for (GameObjectHandle* gameObjectHandle : GameObjectHandle::AllGameObjectHandles) {
		if (!gameObjectHandle->IsValid()) continue;
		GameObject* gameObject = gameObjectHandle->Get();
		if (!gameObject->IsExpired()) {
			gameObject->Update(deltaT);
		}
	}

	EnemyShipManager::GetManager()->Update(deltaT);
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

void GameOverState::RunState(float deltaT)
{
}
