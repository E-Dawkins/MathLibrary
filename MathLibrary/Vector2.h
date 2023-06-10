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

	Vector2 operator + (const Vector2& _other) const;
	Vector2 operator + (float _value) const;
	void operator += (const Vector2& _other);
	void operator += (float _value);

	Vector2 operator - (const Vector2& _other) const;
	Vector2 operator - (float _value) const;
	void operator -= (const Vector2& _other);
	void operator -= (float _value);

	friend Vector2 operator * (float _multi, const Vector2& _vec);
	friend Vector2 operator * (const Vector2& _vec, float _multi);
	void operator *= (float _multiplier);

	Vector2 operator / (float _divisor) const;
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector2& _vector);

	bool operator == (const Vector2& _other);
	bool operator != (const Vector2& _other);

	float& operator [] (int _index);

	float Magnitude() const;
	static float Magnitude(const Vector2& _vector);

	Vector2 Normalized() const;
	static Vector2 Normalized(const Vector2& _vector);

	float Angle(const Vector2& _other) const;
	static float Angle(const Vector2& _to, const Vector2& _from);

	float Dot(const Vector2& _other) const;
	static float Dot(const Vector2& _a, const Vector2& _b);

	static Vector2 Lerp(const Vector2& _from, const Vector2& _to, float _t);
	static float Distance(const Vector2& _a, const Vector2& _b);
	static Vector2 Reflect(const Vector2& _inDirection, const Vector2& _normal);
};