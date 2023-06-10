#pragma once
#include "defs.h"

#include "Vector3.h"

class MATHLIBRARY_API Quaternion
{
public:
	Quaternion() {};
	Quaternion(float _scalar, Vector3 _vector);
	Quaternion(const Quaternion& _value);
	Quaternion(Vector3 _euler);
	~Quaternion() {};

	float s = 0;
	Vector3 v = Vector3(0);

	bool operator == (const Quaternion _q);
	bool operator != (const Quaternion _q);

	Quaternion& operator = (const Quaternion& _value);

	void operator += (const Quaternion& _q);
	Quaternion operator + (const Quaternion& _q) const;
	
	void operator -= (const Quaternion& _q);
	Quaternion operator - (const Quaternion _q) const;

	void operator *= (const Quaternion& _q);
	Quaternion operator * (const Quaternion& _q) const;

	void operator *= (const float _value);
	Quaternion operator * (const float _value) const;

	float Magnitude();

	void Normalize();
	Quaternion Normalized();

	void RNormalize();

	Quaternion Conjugate();

	Quaternion Inverse();

	static Vector3 RotateVector(Vector3 _vector, float _angle, Vector3 _axis);

	Vector3 ToEuler();

};