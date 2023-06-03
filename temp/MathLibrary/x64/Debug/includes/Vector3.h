#pragma once
#include "defs.h"
#include <iostream>

class MATHLIBRARY_API Vector3
{
public:
	Vector3();
	Vector3(float _value);
	Vector3(float _x, float _y, float _z);

	float x = 0;
	float y = 0;
	float z = 0;

	Vector3 operator + (Vector3 _other);
	Vector3 operator + (float _value);
	void operator += (Vector3 _other);
	void operator += (float _value);

	Vector3 operator - (Vector3 _other);
	Vector3 operator - (float _value);
	void operator -= (Vector3 _other);
	void operator -= (float _value);

	Vector3 operator * (float _multiplier);
	void operator *= (float _multiplier);

	Vector3 operator / (float _divisor);
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector3& _vector);

	bool operator == (Vector3 _other);
	bool operator != (Vector3 _other);
};