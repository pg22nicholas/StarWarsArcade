#pragma once
#include "Engine/Public/EngineTypes.h"
#include <math.h>

class exVector3
{
public:
	exVector3(float x, float y, float z);
	exVector3();
	~exVector3();

	exVector3 operator+(const exVector3& rhs) {
		return exVector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	exVector3 operator-(const exVector3& rhs) {
		return exVector3(x - rhs.x, y - rhs.y, z - rhs.z);
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

	static float Dot(const exVector3& a, const exVector3& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	static exVector3 Cross(const exVector3& a, const exVector3& b) {
		return exVector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

	static float Distance(const exVector3& a, const exVector3& b) {
		return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2) + powf(a.z - b.z, 2));
	}

	exVector3 Normalize() {
		float magnitude = sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
		if (magnitude == 0) return exVector3::Zero();
		return exVector3(x / magnitude, y / magnitude, z / magnitude);
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


