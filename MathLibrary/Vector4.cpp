#include "pch.h"
#include "Vector4.h"
#include "Helpers.h"

Vector4 Vector4::zero = Vector4(0);
Vector4 Vector4::one = Vector4(1);
Vector4 Vector4::half = Vector4(0.5f);

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

void Vector4::operator*=(float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
	z *= _multiplier;
	w *= _multiplier;
}

Vector4 operator*(float _multi, Vector4 _vec)
{
	return Vector4(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi, _vec.w * _multi);
}

Vector4 operator*(Vector4 _vec, float _multi)
{
	return Vector4(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi, _vec.w * _multi);
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

float& Vector4::operator[](int _index)
{
	if (_index < 0 || _index > 3)
		throw std::out_of_range("Subscript index is out of range!");

	switch (_index)
	{
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
	}
}

float Vector4::Magnitude()
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2));
}

float Vector4::Magnitude(Vector4 _vector)
{
	return sqrtf(powf(_vector.x, 2) + powf(_vector.y, 2) + powf(_vector.z, 2) + powf(_vector.w, 2));
}

Vector4 Vector4::Normalized()
{
	return *this / Magnitude();
}

Vector4 Vector4::Normalized(Vector4 _vector)
{
	return _vector / Magnitude(_vector);
}

float Vector4::Dot(Vector4 _other)
{
	return (x * _other.x) + (y * _other.y) + (z * _other.z) + (w * _other.w);
}

float Vector4::Dot(Vector4 _a, Vector4 _b)
{
	return (_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z) + (_a.w * _b.w);
}

Vector4 Vector4::Lerp(Vector4 _from, Vector4 _to, float _t)
{
	float tClamp = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));
	return _from + (_to - _from) * tClamp;
}

float Vector4::Distance(Vector4 _a, Vector4 _b)
{
	return (_a - _b).Magnitude();
}