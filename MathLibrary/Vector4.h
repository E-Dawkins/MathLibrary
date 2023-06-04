#pragma once
#include "defs.h"
#include <iostream>

class MATHLIBRARY_API Vector4
{
public:
	Vector4();
	Vector4(float _value);
	Vector4(float _x, float _y, float _z, float _w);

	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;

	Vector4 operator + (Vector4 _other);
	Vector4 operator + (float _value);
	void operator += (Vector4 _other);
	void operator += (float _value);

	Vector4 operator - (Vector4 _other);
	Vector4 operator - (float _value);
	void operator -= (Vector4 _other);
	void operator -= (float _value);

	Vector4 operator * (float _multiplier);
	void operator *= (float _multiplier);

	Vector4 operator / (float _divisor);
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector4& _vector);

	bool operator == (Vector4 _other);
	bool operator != (Vector4 _other);

	float& operator [] (int _index);
};