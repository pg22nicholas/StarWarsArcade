#pragma once
#include "Game/Private/exVector3.h"
#include "Game/Private/PlayerManager.h"

class RenderManager
{
public:
	static RenderManager* GetManager();

	exVector3 GetRenderPosition(exVector3 position);

private:

	RenderManager();
	~RenderManager();

	static RenderManager* sInstance;
};
