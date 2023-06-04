#include "pch.h"
#include "Vector4.h"

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float _value)
{
	x = _value;
	y = _value;
	z = _value;
	w = _value;
}

Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4 Vector4::operator+(Vector4 _other)
{
	return Vector4(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}

Vector4 Vector4::operator+(float _value)
{
	return Vector4(x + _value, y + _value, z + _value, w + _value);
}

void Vector4::operator+=(Vector4 _other)
{
	x += _other.x;
	y += _other.y;
	z += _other.z;
	w += _other.w;
}

void Vector4::operator+=(float _value)
{
	x += _value;
	y += _value;
	z += _value;
	w += _value;
}

Vector4 Vector4::operator-(Vector4 _other)
{
	return Vector4(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}

Vector4 Vector4::operator-(float _value)
{
	return Vector4(x - _value, y - _value, z - _value, w - _value);
}

void Vector4::operator-=(Vector4 _other)
{
	x -= _other.x;
	y -= _other.y;
	z -= _other.z;
	w -= _other.w;
}

void Vector4::operator-=(float _value)
{
	x -= _value;
	y -= _value;
	z -= _value;
	w -= _value;
}

Vector4 Vector4::operator*(float _multiplier)
{
	return Vector4(x * _multiplier, y * _multiplier, z * _multiplier, w * _multiplier);
}

void Vector4::operator*=(float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
	z *= _multiplier;
	w *= _multiplier;
}

Vector4 Vector4::operator/(float _divisor)
{
	return Vector4(x / _divisor, y / _divisor, z / _divisor, w / _divisor);
}

void Vector4::operator/=(float _divisor)
{
	x /= _divisor;
	y /= _divisor;
	z /= _divisor;
	w /= _divisor;
}

void operator<<(std::ostream& _os, const Vector4& _vector)
{
	_os << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ", " << _vector.w << ")";
}

bool Vector4::operator==(Vector4 _other)
{
	return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}

bool Vector4::operator!=(Vector4 _other)
{
	return x != _other.x || y != _other.y || z != _other.z || w != _other.w;
}
