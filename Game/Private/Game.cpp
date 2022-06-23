//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include <thread>
#include "BoxComponent.h"
#include "CircleComponent.h"
#include "TextComponent.h"
#include "ControllerComponent.h"
#include "PlayerManager.h"
#include "BoundsBorderGenerator.h"
#include "EnemyShipManager.h"
#include "Skybox.h"
//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game"; 

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mPlayer(nullptr)
{
	mRunningState = new RunningState();
	mGameOverState = new GameOverState();
	mCurrentState = mRunningState;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
	for (GameObjectHandle* handlePtr : GameObjectHandle::AllGameObjectHandles) {
		if (handlePtr->IsValid()) delete handlePtr->Get();
		delete handlePtr;
	}
	delete mRunningState;
	delete mGameOverState;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "afternight.ttf", 32 );

	new GameObjectHandle((new Skybox())->GetID());

	BoundsBorderGenerator::GenerateBounds();
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	mInput = 0;
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	mInput |= pState[SDL_SCANCODE_R];

	for (ControllerComponent* controller : ControllerComponent::AllGameControllerComponents) {
		controller->ReadInput(pState);
	}
}

void MyGame::Render()
{
	for (BoxComponent* box : BoxComponent::AllGameBoxComponents) {
		box->Render(mCurrentState->GetStateType());
	}

	for (CircleComponent* circle : CircleComponent::AllCircleComponents) {
		circle->Render(mCurrentState->GetStateType());
	}
	for (TextComponent* text : TextComponent::AllTextComponents) {
		text->Render(mCurrentState->GetStateType());
	}
}

void MyGame::CleanUp() {
	for (GameObjectHandle* gameObjectHandle : GameObjectHandle::AllGameObjectHandles) {
		if (!gameObjectHandle->IsValid()) continue;
		GameObject* gameObject = gameObjectHandle->Get();
		if (gameObject->IsExpired()) {
			delete gameObject;
		}
	}
}

void MyGame::Update(float fDeltaT)
{
	PlayerManager::GetManager()->mElapsedTime += fDeltaT;
	mCurrentState->RunState(fDeltaT);
	switch (mCurrentState->GetStateType())
	{
		case StateType::Running:
			if (RunningState* currentRunningState = dynamic_cast<RunningState*>(mCurrentState)) {
				if (PlayerManager::GetManager()->mElapsedTime > PlayerManager::GetManager()->GetPlayer()->kMaxTime) {
					mCurrentState->ExitState();
					mCurrentState = mGameOverState;
					mCurrentState->EnterState();
				}
			}
			break;
		case StateType::GameOver:
			if (GameOverState* currentGameOverState = dynamic_cast<GameOverState*>(mCurrentState)) {
				if (mInput != 0) {
					mCurrentState->ExitState();
					mCurrentState = mRunningState;
					mCurrentState->EnterState();
				}
			}
			break;
	}
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run(float fDeltaT)
{
	CleanUp();
	std::thread UpdateThread(&MyGame::Update, this, fDeltaT);
	std::thread RenderThread(&MyGame::Render, this);
	UpdateThread.join();
	RenderThread.join();
}


