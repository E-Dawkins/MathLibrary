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

	static Vector3 zero;
	static Vector3 one;
	static Vector3 half;

	Vector3 operator + (const Vector3& _other) const;
	Vector3 operator + (float _value) const;
	void operator += (const Vector3& _other);
	void operator += (float _value);

	Vector3 operator - (const Vector3& _other) const;
	Vector3 operator - (float _value) const;
	void operator -= (const Vector3& _other);
	void operator -= (float _value);

	friend Vector3 operator * (float _multi, const Vector3& _vec);
	friend Vector3 operator * (const Vector3& _vec, float _multi);
	void operator *= (float _multiplier);

	Vector3 operator / (float _divisor) const;
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector3& _vector);

	bool operator == (const Vector3& _other);
	bool operator != (const Vector3& _other);

	float& operator [] (int _index);

	float Magnitude() const;
	static float Magnitude(const Vector3& _vector);

	Vector3 Normalized() const;
	static Vector3 Normalized(const Vector3& _vector);
	void Normalize();

	float Angle(const Vector3& _other) const;
	static float Angle(const Vector3& _to, const Vector3& _from);

	Vector3 Cross(const Vector3& _other) const;
	static Vector3 Cross(const Vector3& _a, const Vector3& _b);

	float Dot(const Vector3& _other) const;
	static float Dot(const Vector3& _a, const Vector3& _b);

	static Vector3 Lerp(const Vector3& _from, const Vector3& _to, float _t);
	static float Distance(const Vector3& _a, const Vector3& _b);
	static Vector3 Reflect(const Vector3& _inDirection, const Vector3& _normal);
};