#pragma once
class exVector3
{
public:
	exVector3(float x, float y, float z);
	~exVector3();

	exVector3 operator+(const exVector3& rhs) {
		return exVector3(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ);
	}

	static exVector3 zero() {
		return exVector3(0, 0, 0);
	}
	static exVector3 one() {
		return exVector3(1, 1, 1);
	}

private:
	float mX;
	float mY;
	float mZ;
};


