#pragma once
#include "GameObject.h"
class CircleComponent;

class Explosion : public GameObject
{
public:
    Explosion(exVector3 position);
    ~Explosion();

    void Update(float deltaTime) override;

private:
    exColor* mColor;
    float mRadius;
    CircleComponent* mCircle;
};

