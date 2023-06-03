#include "Vector2.h"

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

Vector2 Vector2::operator * (float _multiplier)
{
	return Vector2(x * _multiplier, y * _multiplier);
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