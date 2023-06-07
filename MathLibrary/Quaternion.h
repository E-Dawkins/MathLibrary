#pragma once
#include "defs.h"
#include <iostream>

class Vector3;
class Matrix4x4;

class MATHLIBRARY_API Quaternion
{
public:
	Quaternion();
	Quaternion(float _x, float _y, float _z, float _w = 0);
	Quaternion(Vector3 _vector, float _scalar);

	float x;
	float y;
	float z;
	float w;

	Vector3 Vector();

	static Quaternion identity;

	float& operator [] (int _index);

	friend Quaternion operator * (Quaternion _lhs, Quaternion _rhs);
	friend Quaternion operator * (float _lhs, Quaternion _rhs);
	friend Quaternion operator * (Quaternion _lhs, float _rhs);

	friend Quaternion operator + (Quaternion _lhs, Quaternion _rhs);
	friend Quaternion operator - (Quaternion _lhs, Quaternion _rhs);

	bool operator == (Quaternion _other);
	bool operator != (Quaternion _other);

	friend void operator << (std::ostream& _os, Quaternion& _quat);

	float Dot(Quaternion _other);
	static float Dot(Quaternion _a, Quaternion _b);

	bool IsIdentity();
	static bool IsIdentity(Quaternion _quat);

	float Magnitude();
	static float Magnitude(Quaternion _quat);

	Quaternion Conjugate();
	static Quaternion Conjugate(Quaternion _quat);

	static Quaternion Lerp(Quaternion _from, Quaternion _to, float _t);
	static Quaternion Slerp(Quaternion _from, Quaternion _to, float _t);
};