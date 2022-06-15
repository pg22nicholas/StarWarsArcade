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
#include "Ball.h"
#include "Box.h"
#include "BoxComponent.h"
#include "CircleComponent.h"
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
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
	for (GameObjectHandle* handlePtr : GameObjectHandle::AllGameObjectHandles) {
		if (handlePtr->IsValid()) delete handlePtr->Get();
		delete handlePtr;
	}
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize( exEngineInterface* pEngine )
{
	mEngine = pEngine;

	mFontID = mEngine->LoadFont( "afternight.ttf", 32 );

	//Ship* ship = new Ship();
	//ship->Initialize();

	//Bullet* bullet = new Bullet();
	//bullet->Initialize();

	mPlayer = new Player();
	new GameObjectHandle(mPlayer->GetID());

	new GameObjectHandle((new Skybox())->GetID());

	mPlayer->Initialize();
	new GameObjectHandle((new EnemyShip())->GetID());

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
	const Uint8 *pState = SDL_GetKeyboardState( &nKeys );

	mInput |= pState[SDL_SCANCODE_LEFT];
	mInput |= pState[SDL_SCANCODE_RIGHT] << 1;

	for (ControllerComponent* controller : ControllerComponent::AllGameControllerComponents) {
		controller->ReadInput(pState);
	}
}

void MyGame::Render()
{
	for (BoxComponent* box : BoxComponent::AllGameBoxComponents) {
		box->Render();
	}
	for (CircleComponent* circle : CircleComponent::AllCircleComponents) {
		circle->Render();
	} 
}

void MyGame::Update(float fDeltaT)
{
	for (GameObjectHandle* gameObjectHandle : GameObjectHandle::AllGameObjectHandles) {
		if (!gameObjectHandle->IsValid()) continue;
		GameObject* gameObject = gameObjectHandle->Get();
		if (gameObject->IsExpired()) {
			delete gameObject;
		}
	}
	for (PhysicsComponent* physicsComponent : PhysicsComponent::mAllPhysicsComponents) {
		physicsComponent->Update(fDeltaT);
	}

	EnemyShipManager::GetManager()->Update(fDeltaT);
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run(float fDeltaT)
{
	Update(fDeltaT);
	Render();
}


