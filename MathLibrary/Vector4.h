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

	static Vector4 zero;
	static Vector4 one;
	static Vector4 half;

	Vector4 operator + (Vector4 _other);
	Vector4 operator + (float _value);
	void operator += (Vector4 _other);
	void operator += (float _value);

	Vector4 operator - (Vector4 _other);
	Vector4 operator - (float _value);
	void operator -= (Vector4 _other);
	void operator -= (float _value);

	friend Vector4 operator * (float _multi, Vector4 _vec);
	friend Vector4 operator * (Vector4 _vec, float _multi);
	void operator *= (float _multiplier);

	Vector4 operator / (float _divisor);
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector4& _vector);

	bool operator == (Vector4 _other);
	bool operator != (Vector4 _other);

	float& operator [] (int _index);

	float Magnitude();
	static float Magnitude(Vector4 _vector);

	Vector4 Normalized();
	static Vector4 Normalized(Vector4 _vector);

	float Dot(Vector4 _other);
	static float Dot(Vector4 _a, Vector4 _b);

	static Vector4 Lerp(Vector4 _from, Vector4 _to, float _t);
	static float Distance(Vector4 _a, Vector4 _b);
};