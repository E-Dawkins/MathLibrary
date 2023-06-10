#pragma once
#include "pch.h"
#include "Vector3.h"
#include "Helpers.h"

// Shorthand for Vector3(0, 0, 0)
Vector3 Vector3::zero = Vector3(0);

// Shorthand for Vector3(1, 1, 1)
Vector3 Vector3::one = Vector3(1);

// Shorthand for Vector3(0.5, 0.5, 0.5)
Vector3 Vector3::half = Vector3(0.5f);

// Construct a vector(0, 0, 0)
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

// Constructs a vector(_value, _value, _value)
Vector3::Vector3(float _value)
{
	x = _value;
	y = _value;
	z = _value;
}

// Constructs a vector(_x, _y, _z)
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

// Adds two vectors component wise
Vector3 Vector3::operator+(const Vector3& _other) const
{
	return Vector3(x + _other.x, y + _other.y, z + _other.z);
}

// Adds _value to this vectors components
Vector3 Vector3::operator+(float _value) const
{
	return Vector3(x + _value, y + _value, z + _value);
}

// Adds _other components to this vector
void Vector3::operator+=(const Vector3& _other)
{
	x += _other.x;
	y += _other.y;
	z += _other.z;
}

// Adds _value to each component of this vector
void Vector3::operator+=(float _value)
{
	x += _value;
	y += _value;
	z += _value;
}

// Subtracts two vectors component wise
Vector3 Vector3::operator-(const Vector3& _other) const
{
	return Vector3(x - _other.x, y - _other.y, z - _other.z);
}

// Subtracts _value from each component of this vector
Vector3 Vector3::operator-(float _value) const
{
	return Vector3(x - _value, y - _value, z - _value);
}

// Subtracts _other from this vector
void Vector3::operator-=(const Vector3& _other)
{
	x -= _other.x;
	y -= _other.y;
	z -= _other.z;
}

// Subtracts _value from this vectors components
void Vector3::operator-=(float _value)
{
	x -= _value;
	y -= _value;
	z -= _value;
}

// Multipliers components by _multiplier
void Vector3::operator*=(float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
	z *= _multiplier;
}

// Divided components by _divisor
Vector3 Vector3::operator/(float _divisor) const
{
	return Vector3(x / _divisor, y / _divisor, z / _divisor);
}

// Divides components by _divisor
void Vector3::operator/=(float _divisor)
{
	x /= _divisor;
	y /= _divisor;
	z /= _divisor;
}

// Multiplies a vector by a float
Vector3 operator*(float _multi, const Vector3& _vec)
{
	return Vector3(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi);
}

// Multiplies a vector by a float
Vector3 operator*(const Vector3& _vec, float _multi)
{
	return Vector3(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi);
}

// Appends (x, y, z) to _os
void operator<<(std::ostream& _os, const Vector3& _vector)
{
	_os << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ")";
}

// Returns true if every component == _other component
bool Vector3::operator==(const Vector3& _other)
{
	return x == _other.x && y == _other.y && z == _other.z;
}

// Returns true if any component != _other component
bool Vector3::operator!=(const Vector3& _other)
{
	return x != _other.x || y != _other.y || z != _other.z;
}

// Returns component at _index, i.e. 0 => x
float& Vector3::operator[](int _index)
{
	if (_index < 0 || _index > 2)
		throw std::out_of_range("Subscript index is out of range!");

	switch (_index)
	{
		case 0: return x;
		case 1: return y;
		case 2: return z;
	}

	return x;
}

// Returns magnitude of this vector
float Vector3::Magnitude() const
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

// Returns magnitude of _vector
float Vector3::Magnitude(const Vector3& _vector)
{
	return sqrtf(powf(_vector.x, 2) + powf(_vector.y, 2) + powf(_vector.z, 2));
}

// Returns this vector normalized
Vector3 Vector3::Normalized() const
{
	return *this / Magnitude();
}

// Returns _vector normalized
Vector3 Vector3::Normalized(const Vector3& _vector)
{
	return _vector / Magnitude(_vector);
}

void Vector3::Normalize()
{
	float magnitude = Magnitude();

	x /= Magnitude();
	y /= Magnitude();
	z /= Magnitude();
}

// Returns angle between this and _other
float Vector3::Angle(const Vector3& _other) const
{
	float totalMagnitude = Magnitude() * _other.Magnitude();
	float cosResult = Dot(_other) / totalMagnitude;
	return HELPERS::Rad2Deg(acosf(cosResult));
}

// Returns angle between _to and _from
float Vector3::Angle(const Vector3& _to, const Vector3& _from)
{
	float totalMagnitude = Magnitude(_to) * Magnitude(_from);
	float cosResult = Dot(_to, _from) / totalMagnitude;
	return HELPERS::Rad2Deg(acosf(cosResult));
}

// Gets cross product between this and _other
Vector3 Vector3::Cross(const Vector3& _other) const
{
	return Vector3
	(
		(y * _other.z) - (z * _other.y),
		(z * _other.x) - (x * _other.z),
		(x * _other.y) - (y * _other.x)
	);
}

// Gets cross product between _a and _b
Vector3 Vector3::Cross(const Vector3& _a, const Vector3& _b)
{
	return Vector3
	(
		(_a.y * _b.z) - (_a.z * _b.y),
		(_a.z * _b.x) - (_a.x * _b.z),
		(_a.x * _b.y) - (_a.y * _b.x)
	);
}

// Gets dot product between this and _other
float Vector3::Dot(const Vector3& _other) const
{
	return (x * _other.x) + (y * _other.y) + (z * _other.z);
}

// Gets dot product between _a and _b
float Vector3::Dot(const Vector3& _a, const Vector3& _b)
{
	return (_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z);
}

// Lerps between _from, _to by _t
Vector3 Vector3::Lerp(const Vector3& _from, const Vector3& _to, float _t)
{
	float tClamp = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));
	return _from + (_to - _from) * tClamp;
}

// Gets distance between _a and _b
float Vector3::Distance(const Vector3& _a, const Vector3& _b)
{
	return (_a - _b).Magnitude();
}

// Gets _inDirection reflected over _normal
Vector3 Vector3::Reflect(const Vector3& _inDirection, const Vector3& _normal)
{
	return _inDirection - 2.f * Dot(_inDirection, _normal) * _normal;
}
