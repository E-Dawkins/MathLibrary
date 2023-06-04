#include "pch.h"
#include "Vector3.h"

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

Vector3 Vector3::operator+(Vector3 _other)
{
	return Vector3(x + _other.x, y + _other.y, z + _other.z);
}

Vector3 Vector3::operator+(float _value)
{
	return Vector3(x + _value, y + _value, z + _value);
}

void Vector3::operator+=(Vector3 _other)
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

Vector3 Vector3::operator-(Vector3 _other)
{
	return Vector3(x - _other.x, y - _other.y, z - _other.z);
}

Vector3 Vector3::operator-(float _value)
{
	return Vector3(x - _value, y - _value, z - _value);
}

void Vector3::operator-=(Vector3 _other)
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

Vector3 Vector3::operator*(float _multiplier)
{
	return Vector3(x * _multiplier, y * _multiplier, z * _multiplier);
}

void Vector3::operator*=(float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
	z *= _multiplier;
}

Vector3 Vector3::operator/(float _divisor)
{
	return Vector3(x / _divisor, y / _divisor, z / _divisor);
}

void Vector3::operator/=(float _divisor)
{
	x /= _divisor;
	y /= _divisor;
	z /= _divisor;
}

void operator<<(std::ostream& _os, const Vector3& _vector)
{
	_os << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ")";
}

bool Vector3::operator==(Vector3 _other)
{
	return x == _other.x && y == _other.y && z == _other.z;
}

bool Vector3::operator!=(Vector3 _other)
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
}
