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

	Vector4 operator + (const Vector4& _other) const;
	Vector4 operator + (float _value) const;
	void operator += (const Vector4& _other);
	void operator += (float _value);

	Vector4 operator - (const Vector4& _other) const;
	Vector4 operator - (float _value) const;
	void operator -= (const Vector4& _other);
	void operator -= (float _value);

	friend Vector4 operator * (float _multi, const Vector4& _vec);
	friend Vector4 operator * (const Vector4& _vec, float _multi);
	void operator *= (float _multiplier);

	Vector4 operator / (float _divisor) const;
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector4& _vector);

	bool operator == (const Vector4& _other);
	bool operator != (const Vector4& _other);

	float& operator [] (int _index);

	float Magnitude() const;
	static float Magnitude(const Vector4& _vector);

	Vector4 Normalized() const;
	static Vector4 Normalized(const Vector4& _vector);
	void Normalize();

	float Dot(const Vector4& _other) const;
	static float Dot(const Vector4& _a, const Vector4& _b);

	static Vector4 Lerp(const Vector4& _from, const Vector4& _to, float _t);
	static float Distance(const Vector4& _a, const Vector4& _b);
};