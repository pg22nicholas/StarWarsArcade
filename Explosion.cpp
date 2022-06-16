#include "Explosion.h"
#include <cstdlib>
#include "CircleComponent.h"
#include "Engine/Public/EngineTypes.h"

const float gExplosionRadiusSpeed = 250.0f;
const float gExplosionRadiusStart = 40.0f;
const float gExplosionRadiusTarget = 135.0f;

Explosion::Explosion(exVector3 position)
{
	mCircle = new CircleComponent(this, gExplosionRadiusStart);
	mColor = new exColor();
	AddComponent(mCircle);
}

Explosion::~Explosion()
{
	delete mColor;
}

void Explosion::Update(float fDeltaT)
{
	mColor->mColor[0] = rand() % 255;
	mColor->mColor[1] = rand() % 255;
	mColor->mColor[2] = rand() % 255;
	
	mCircle->SetColor(*mColor);
	
	mRadius += gExplosionRadiusSpeed * fDeltaT;
	mCircle->SetRadius(mRadius);

	if (mRadius > gExplosionRadiusTarget)
	{
		Expire();
	}
}
