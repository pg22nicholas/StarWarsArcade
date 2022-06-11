#pragma once
#include "Engine/Public/EngineTypes.h"

class exVector3
{
public:
	exVector3(float x, float y, float z);
	exVector3();
	~exVector3();

	exVector3 operator+(const exVector3& rhs) {
		return exVector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	exVector3& operator+=(const exVector3& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}

	exVector3 operator*(const float& rhs) {
		return exVector3(x * rhs, y * rhs, z * rhs);
	}

	static exVector3 Zero() {
		return exVector3(0, 0, 0);
	}
	static exVector3 One() {
		return exVector3(1, 1, 1);
	}

	exVector2 getExVector2() {
		exVector2 vec;
		vec.x = x;
		vec.y = y;
		return vec;
	}
	
	float x;
	float y;
	float z;

private:
	
};


