#pragma once
#include "pch.h"
#include "Quaternion.h"
#include "Helpers.h"

using namespace HELPERS;

// Constructs quaternion with _scalar real, _vector imaginary
Quaternion::Quaternion(float _scalar, Vector3 _vector)
{
	s = _scalar;
	v = _vector;
}

// Copy constructor, copies _value to our components
Quaternion::Quaternion(const Quaternion& _value)
{
	s = _value.s;
	v = _value.v;
}

// Constructs a quaternion from euler angles
Quaternion::Quaternion(Vector3 _euler)
{
	double yaw = _euler[0];
	double pitch = _euler[1];
	double roll = _euler[2];

	v[0] = sin(roll / 2.0) * cos(pitch / 2.0) * cos(yaw / 2.0) - cos(roll / 2.0) * sin(pitch / 2.0) * sin(yaw / 2.0);
	v[1] = cos(roll / 2.0) * sin(pitch / 2.0) * cos(yaw / 2.0) + sin(roll / 2.0) * cos(pitch / 2.0) * sin(yaw / 2.0);
	v[2] = cos(roll / 2.0) * cos(pitch / 2.0) * sin(yaw / 2.0) - sin(roll / 2.0) * sin(pitch / 2.0) * cos(yaw / 2.0);
	s = cos(roll / 2.0) * cos(pitch / 2.0) * cos(yaw / 2.0) + sin(roll / 2.0) * sin(pitch / 2.0) * sin(yaw / 2.0);
}

// Returns true if every component == _q
bool Quaternion::operator==(const Quaternion _q)
{
	return s == _q.s && v == _q.v;
}

// Returns true if any component != _q
bool Quaternion::operator!=(const Quaternion _q)
{
	return s != _q.s || v != _q.v;
}

// Copy constructor, copies _value to our components and returns this
Quaternion& Quaternion::operator=(const Quaternion& _value)
{
	s = _value.s;
	v = _value.v;

	return *this;
}

// Adds _q to this
void Quaternion::operator+=(const Quaternion& _q)
{
	s += _q.s;
	v += _q.v;
}

// Adds _q and this, then returns result
Quaternion Quaternion::operator+(const Quaternion& _q) const
{
	float scalar = s + _q.s;
	Vector3 imaginary = v + _q.v;

	return Quaternion(scalar, imaginary);
}

// Subtracts _q from this
void Quaternion::operator-=(const Quaternion& _q)
{
	s -= _q.s;
	v -= _q.v;
}

// Subtracts _q and this, then returns result
Quaternion Quaternion::operator-(const Quaternion _q) const
{
	float scalar = s - _q.s;
	Vector3 imaginary = v - _q.v;

	return Quaternion(scalar, imaginary);
}

// Performs quaternion multiplication between this and _q
void Quaternion::operator*=(const Quaternion& _q)
{
	float scalar = s * _q.s - v.Dot(_q.v);
	Vector3 imaginary = s * _q.v + _q.s * v + v.Cross(_q.v);

	s = scalar;
	v = imaginary;
}

// Returns quaternion multiplication of this and _q
Quaternion Quaternion::operator*(const Quaternion& _q) const
{
	float scalar = s * _q.s - v.Dot(_q.v);
	Vector3 imaginary = s * _q.v + _q.s * v + v.Cross(_q.v);

	return Quaternion(scalar, imaginary);
}

// Multiplies each component by _value
void Quaternion::operator*=(const float _value)
{
	s *= _value;
	v *= _value;
}

// Returns quaternion constructed by this * _value
Quaternion Quaternion::operator*(const float _value) const
{
	return Quaternion(s * _value, v * _value);
}

// Appends _q to _os
void operator<<(std::ostream& _os, const Quaternion& _q)
{
	_os << "(" << _q.s << ", {" << _q.v.x << ", " << _q.v.y << ", " << _q.v.z << "})";
}

// Gets magnitude of this quaternion
float Quaternion::Magnitude()
{
	float s2 = s * s;
	float v2 = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];

	return sqrt(s2 + v2);
}

// Normalizes this quaternion
void Quaternion::Normalize()
{
	float magnitude = Magnitude();

	if (magnitude != 0)
	{
		s /= magnitude;
		v /= magnitude;
	}
}

// Returns this normalized
Quaternion Quaternion::Normalized()
{
	float magnitude = Magnitude();
	return Quaternion(s / magnitude, v / magnitude);
}

// Returns this normalized for rotation
void Quaternion::RNormalize()
{
	float angle = Deg2Rad(s);
	
	s = cosf(angle * 0.5);
	v = v.Normalized() * sinf(angle * 0.5);
}

// Gets conjugate of this quaternion
Quaternion Quaternion::Conjugate()
{
	return Quaternion(s, v * -1.f);
}

// Gets inverse of this quaternion
Quaternion Quaternion::Inverse()
{
	float magnitude = Magnitude();
	magnitude = 1.f / (magnitude * magnitude);

	Quaternion conjugate = Conjugate();

	float scalar = conjugate.s * magnitude;
	Vector3 imaginary = conjugate.v * magnitude;

	return Quaternion(scalar, imaginary);
}

// Rotates _vector by _angle around _axis
Vector3 Quaternion::RotateVector(Vector3 _vector, float _angle, Vector3 _axis)
{
	// Vector -> Pure Quaternion
	Quaternion p(0, _vector);

	// Normalize axis-vector
	_axis = _axis.Normalized();

	// Create real quaternion
	Quaternion q(_angle, _axis);

	// Quaternion -> Rotation Normalized Quaternion
	q.RNormalize();

	// Get inverse of the quaternion
	Quaternion qInverse = q.Inverse();

	// Rotate the quaternion
	Quaternion rotatedVector = q * p * qInverse;

	// Return the vector part of the quaternion
	return rotatedVector.v;
}

// Converts this quaternion to its' euler representation
Vector3 Quaternion::ToEuler()
{
	float x = v[0];
	float y = v[1];
	float z = v[2];
	float w = s;

	double t0 = 2.0 * (w * x + y * z);
	double t1 = 1.0 - 2.0 * (x * x + y * y);
	double roll = atan2(t0, t1);

	double t2 = 2.0 * (w * y - z * x);
	t2 = t2 > 1.0 ? 1.0 : t2;
	t2 = t2 < -1.0 ? -1.0 : t2;
	double pitch = asin(t2);

	double t3 = 2.0 * (w * z + x * y);
	double t4 = 1.0 - 2.0 * (y * y + z * z);
	double yaw = atan2(t3, t4);

	return Vector3(yaw, pitch, roll);
}
