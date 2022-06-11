//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include <vector>
#include "GameObject.h"
#include "CircleComponent.h"
#include "BoxComponent.h"
#include "PhysicsComponent.h"
#include "Ship.h"
#include "Bullet.h"
#include "Player.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void		 		OnEventsConsumed();

	virtual void				Run( float fDeltaT );

private:

	exEngineInterface*			mEngine;

	int							mFontID;

	int							mInput;	// captures all input keys

	std::vector<GameObject*>    mAllGameObjects;

	void						Render();
	void						Update(float fDeltaT);
	void						ProcessInputs();
	Player*						mPlayer;

};
