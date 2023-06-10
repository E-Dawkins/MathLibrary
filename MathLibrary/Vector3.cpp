#pragma once
#include "pch.h"
#include "Vector3.h"
#include "Helpers.h"

Vector3 Vector3::zero = Vector3(0);
Vector3 Vector3::one = Vector3(1);
Vector3 Vector3::half = Vector3(0.5f);

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float _value)
{
	x = _value;
	y = _value;
	z = _value;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3 Vector3::operator+(const Vector3& _other) const
{
	return Vector3(x + _other.x, y + _other.y, z + _other.z);
}

Vector3 Vector3::operator+(float _value) const
{
	return Vector3(x + _value, y + _value, z + _value);
}

void Vector3::operator+=(const Vector3& _other)
{
	x += _other.x;
	y += _other.y;
	z += _other.z;
}

void Vector3::operator+=(float _value)
{
	x += _value;
	y += _value;
	z += _value;
}

Vector3 Vector3::operator-(const Vector3& _other) const
{
	return Vector3(x - _other.x, y - _other.y, z - _other.z);
}

Vector3 Vector3::operator-(float _value) const
{
	return Vector3(x - _value, y - _value, z - _value);
}

void Vector3::operator-=(const Vector3& _other)
{
	x -= _other.x;
	y -= _other.y;
	z -= _other.z;
}

void Vector3::operator-=(float _value)
{
	x -= _value;
	y -= _value;
	z -= _value;
}



void Vector3::operator*=(float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
	z *= _multiplier;
}

Vector3 Vector3::operator/(float _divisor) const
{
	return Vector3(x / _divisor, y / _divisor, z / _divisor);
}

void Vector3::operator/=(float _divisor)
{
	x /= _divisor;
	y /= _divisor;
	z /= _divisor;
}

Vector3 operator*(float _multi, const Vector3& _vec)
{
	return Vector3(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi);
}

Vector3 operator*(const Vector3& _vec, float _multi)
{
	return Vector3(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi);
}

void operator<<(std::ostream& _os, const Vector3& _vector)
{
	_os << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ")";
}

bool Vector3::operator==(const Vector3& _other)
{
	return x == _other.x && y == _other.y && z == _other.z;
}

bool Vector3::operator!=(const Vector3& _other)
{
	return x != _other.x || y != _other.y || z != _other.z;
}

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

float Vector3::Magnitude() const
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

float Vector3::Magnitude(const Vector3& _vector)
{
	return sqrtf(powf(_vector.x, 2) + powf(_vector.y, 2) + powf(_vector.z, 2));
}

Vector3 Vector3::Normalized() const
{
	return *this / Magnitude();
}

Vector3 Vector3::Normalized(const Vector3& _vector)
{
	return _vector / Magnitude(_vector);
}

float Vector3::Angle(const Vector3& _other) const
{
	float totalMagnitude = Magnitude() * _other.Magnitude();
	float cosResult = Dot(_other) / totalMagnitude;
	return HELPERS::Rad2Deg(acosf(cosResult));
}

float Vector3::Angle(const Vector3& _to, const Vector3& _from)
{
	float totalMagnitude = Magnitude(_to) * Magnitude(_from);
	float cosResult = Dot(_to, _from) / totalMagnitude;
	return HELPERS::Rad2Deg(acosf(cosResult));
}

Vector3 Vector3::Cross(const Vector3& _other) const
{
	return Vector3
	(
		(y * _other.z) - (z * _other.y),
		(z * _other.x) - (x * _other.z),
		(x * _other.y) - (y * _other.x)
	);
}

Vector3 Vector3::Cross(const Vector3& _a, const Vector3& _b)
{
	return Vector3
	(
		(_a.y * _b.z) - (_a.z * _b.y),
		(_a.z * _b.x) - (_a.x * _b.z),
		(_a.x * _b.y) - (_a.y * _b.x)
	);
}

float Vector3::Dot(const Vector3& _other) const
{
	return (x * _other.x) + (y * _other.y) + (z * _other.z);
}

float Vector3::Dot(const Vector3& _a, const Vector3& _b)
{
	return (_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z);
}

Vector3 Vector3::Lerp(const Vector3& _from, const Vector3& _to, float _t)
{
	float tClamp = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));
	return _from + (_to - _from) * tClamp;
}

float Vector3::Distance(const Vector3& _a, const Vector3& _b)
{
	return (_a - _b).Magnitude();
}

Vector3 Vector3::Reflect(const Vector3& _inDirection, const Vector3& _normal)
{
	return _inDirection - 2.f * Dot(_inDirection, _normal) * _normal;
}
