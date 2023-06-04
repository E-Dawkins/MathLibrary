#pragma once
#include "defs.h"
#include <iostream>

class MATHLIBRARY_API Vector2
{
public:
	Vector2();
	Vector2(float _value);
	Vector2(float _x, float _y);

	float x = 0;
	float y = 0;

	static Vector2 zero;
	static Vector2 one;
	static Vector2 half;

	Vector2 operator + (Vector2 _other);
	Vector2 operator + (float _value);
	void operator += (Vector2 _other);
	void operator += (float _value);

	Vector2 operator - (Vector2 _other);
	Vector2 operator - (float _value);
	void operator -= (Vector2 _other);
	void operator -= (float _value);

	friend Vector2 operator * (float _multi, Vector2 _vec);
	friend Vector2 operator * (Vector2 _vec, float _multi);
	void operator *= (float _multiplier);

	Vector2 operator / (float _divisor);
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector2& _vector);

	bool operator == (Vector2 _other);
	bool operator != (Vector2 _other);

	float& operator [] (int _index);

	float Magnitude();
	static float Magnitude(Vector2 _vector);

	Vector2 Normalized();
	static Vector2 Normalized(Vector2 _vector);

	float Angle(Vector2 _other);
	static float Angle(Vector2 _to, Vector2 _from);

	float Cross(Vector2 _other);
	static float Cross(Vector2 _a, Vector2 _b);

	static Vector2 Lerp(Vector2 _from, Vector2 _to, float _t);
	static float Distance(Vector2 _a, Vector2 _b);
	static Vector2 Reflect(Vector2 _inDirection, Vector2 _normal);
};