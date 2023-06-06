#pragma once
#include "Vector2.h"
#include "Helpers.h"

Vector2 Vector2::zero = Vector2(0);
Vector2 Vector2::one = Vector2(1);
Vector2 Vector2::half = Vector2(0.5f);

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float _value)
{
	x = _value;
	y = _value;
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2 Vector2::operator + (Vector2 _other)
{
	return Vector2(x + _other.x, y + _other.y);
}

Vector2 Vector2::operator + (float _value)
{
	return Vector2(x + _value, y + _value);
}

void Vector2::operator += (Vector2 _other)
{
	x += _other.x;
	y += _other.y;
}

void Vector2::operator += (float _value)
{
	x += _value;
	y += _value;
}

Vector2 Vector2::operator - (Vector2 _other)
{
	return Vector2(x - _other.x, y - _other.y);
}

Vector2 Vector2::operator - (float _value)
{
	return Vector2(x - _value, y - _value);
}

void Vector2::operator -= (Vector2 _other)
{
	x -= _other.x;
	y -= _other.y;
}

void Vector2::operator -= (float _value)
{
	x -= _value;
	y -= _value;
}

Vector2 operator*(float _multi, Vector2 _vec)
{
	return Vector2(_vec.x * _multi, _vec.y * _multi);
}

Vector2 operator*(Vector2 _vec, float _multi)
{
	return Vector2(_vec.x * _multi, _vec.y * _multi);
}

void Vector2::operator *= (float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
}

Vector2 Vector2::operator / (float _divisor)
{
	return Vector2(x / _divisor, y / _divisor);
}

void Vector2::operator /= (float _divisor)
{
	x /= _divisor;
	y /= _divisor;
}

void operator<<(std::ostream& _os, const Vector2& _vec)
{
	_os << "(" << _vec.x << ", " << _vec.y << ")";
}

bool Vector2::operator==(Vector2 _other)
{
	return x == _other.x && y == _other.y;
}

bool Vector2::operator!=(Vector2 _other)
{
	return x != _other.x || y != _other.y;
}

float& Vector2::operator[](int _index)
{
	if (_index < 0 || _index > 1)
		throw std::out_of_range("Subscript index is out of range!");

	switch (_index)
	{
		case 0: return x;
		case 1: return y;
	}

	return x;
}

float Vector2::Magnitude()
{
	return sqrtf(powf(x, 2) + powf(y, 2));
}

float Vector2::Magnitude(Vector2 _vector)
{
	return sqrtf(powf(_vector.x, 2) + powf(_vector.y, 2));
}

Vector2 Vector2::Normalized()
{
	return *this / Magnitude();
}

Vector2 Vector2::Normalized(Vector2 _vector)
{
	return _vector / Magnitude(_vector);
}

float Vector2::Angle(Vector2 _other)
{
	float totalMagnitude = Magnitude() * _other.Magnitude();
	float cosResult = Cross(_other) / (totalMagnitude);
	return HELPERS::Rad2Deg(acosf(cosResult));
}

float Vector2::Angle(Vector2 _to, Vector2 _from)
{
	float totalMagnitude = Magnitude(_to) * Magnitude(_from);
	float cosResult = Cross(_to, _from) / (totalMagnitude);
	return HELPERS::Rad2Deg(acosf(cosResult));
}

float Vector2::Cross(Vector2 _other)
{
	return (x * _other.x) + (y * _other.y);
}

float Vector2::Cross(Vector2 _a, Vector2 _b)
{
	return (_a.x * _b.x) + (_a.y * _b.y);
}

Vector2 Vector2::Lerp(Vector2 _from, Vector2 _to, float _t)
{
	float tClamp = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));
	return _from + (_to - _from) * tClamp;
}

float Vector2::Distance(Vector2 _a, Vector2 _b)
{
	return (_a - _b).Magnitude();
}

Vector2 Vector2::Reflect(Vector2 _inDirection, Vector2 _normal)
{
	return _inDirection - 2.f * Cross(_inDirection, _normal) * _normal;
}