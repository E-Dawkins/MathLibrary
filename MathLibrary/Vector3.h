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

	Vector3 operator + (Vector3 _other);
	Vector3 operator + (float _value);
	void operator += (Vector3 _other);
	void operator += (float _value);

	Vector3 operator - (Vector3 _other);
	Vector3 operator - (float _value);
	void operator -= (Vector3 _other);
	void operator -= (float _value);

	friend Vector3 operator * (float _multi, Vector3 _vec);
	friend Vector3 operator * (Vector3 _vec, float _multi);
	void operator *= (float _multiplier);

	Vector3 operator / (float _divisor);
	void operator /= (float _divisor);

	friend void operator << (std::ostream& _os, const Vector3& _vector);

	bool operator == (Vector3 _other);
	bool operator != (Vector3 _other);

	float& operator [] (int _index);

	float Magnitude();
	static float Magnitude(Vector3 _vector);

	Vector3 Normalized();
	static Vector3 Normalized(Vector3 _vector);

	float Angle(Vector3 _other);
	static float Angle(Vector3 _to, Vector3 _from);

	float Cross(Vector3 _other);
	static float Cross(Vector3 _a, Vector3 _b);

	static Vector3 Lerp(Vector3 _from, Vector3 _to, float _t);
	static float Distance(Vector3 _a, Vector3 _b);
	static Vector3 Reflect(Vector3 _inDirection, Vector3 _normal);
};