#include "RenderManager.h"
#include "Bounds.h"

RenderManager* RenderManager::GetManager()
{
	if (sInstance == nullptr) {
		sInstance = new RenderManager();
	}
	return sInstance;
}

exVector3 RenderManager::GetRenderPosition(exVector3 position)
{
	return position - PlayerManager::GetManager()->GetPlayer()->GetTransform()->GetPosition() + exVector3(Bounds::centerX, Bounds::centerY, 0);
}

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

RenderManager* RenderManager::sInstance = nullptr;