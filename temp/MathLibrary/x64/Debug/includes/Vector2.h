#pragma once
#include "defs.h"
#include <iostream>
#include "Vector3.h"

class MATHLIBRARY_API Vector2
{
public:
	Vector2();
	Vector2(float _value);
	Vector2(float _x, float _y);

	float x = 0;
	float y = 0;

	Vector2 operator + (Vector2 _other);
	Vector2 operator + (float _value);
	void operator += (Vector2 _other);
	void operator += (float _value);

	Vector2 operator - (Vector2 _other);
	Vector2 operator - (float _value);
	void operator -= (Vector2 _other);
	void operator -= (float _value);

	Vector2 operator * (float _multiplier);
	void operator *= (float _multiplier);

	Vector2 operator / (float _divisor);
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector2& _vector);

	bool operator == (Vector2 _other);
	bool operator != (Vector2 _other);
};