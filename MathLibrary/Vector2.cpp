#pragma once
#include "Vector2.h"
#include "Helpers.h"

// Shorthand for Vector2(0, 0)
Vector2 Vector2::zero = Vector2(0);

// Shorthand for Vector2(1, 1)
Vector2 Vector2::one = Vector2(1);

// Shorthand for Vector2(0.5f, 0.5f)
Vector2 Vector2::half = Vector2(0.5f);

// Constructs Vector2(0, 0)
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

// Constructs Vector2(_value, _value)
Vector2::Vector2(float _value)
{
	x = _value;
	y = _value;
}

// Constructs Vector2(_x, _y)
Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

// Adds two vectors component-wise
Vector2 Vector2::operator + (const Vector2& _other) const
{
	return Vector2(x + _other.x, y + _other.y);
}

// Adds _value to each component of vector
Vector2 Vector2::operator + (float _value) const
{
	return Vector2(x + _value, y + _value);
}

// Adds right vector's components to left vectors'
void Vector2::operator += (const Vector2& _other)
{
	x += _other.x;
	y += _other.y;
}

// Adds _value to left vectors' components
void Vector2::operator += (float _value)
{
	x += _value;
	y += _value;
}

// Subtracts two vectors component-wise
Vector2 Vector2::operator - (const Vector2& _other) const
{
	return Vector2(x - _other.x, y - _other.y);
}

// Subtracts _value from each component
Vector2 Vector2::operator - (float _value) const
{
	return Vector2(x - _value, y - _value);
}

// Subtracts right vector's components from left vectors'
void Vector2::operator -= (const Vector2& _other)
{
	x -= _other.x;
	y -= _other.y;
}
// Subtracts _value from left vectors' components
void Vector2::operator -= (float _value)
{
	x -= _value;
	y -= _value;
}

// Returns a vector multiplied component-wise
Vector2 operator*(float _multi, const Vector2& _vec)
{
	return Vector2(_vec.x * _multi, _vec.y * _multi);
}

// Returns a vector multiplied component-wise
Vector2 operator*(const Vector2& _vec, float _multi)
{
	return Vector2(_vec.x * _multi, _vec.y * _multi);
}

// Multiplies vectors' components by _multiplier
void Vector2::operator *= (float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
}

// Returns a vector divided by _divisor
Vector2 Vector2::operator / (float _divisor) const
{
	return Vector2(x / _divisor, y / _divisor);
}

// Divides vectors' components by _divisor
void Vector2::operator /= (float _divisor)
{
	x /= _divisor;
	y /= _divisor;
}

// Appends (x, y) to _os
void operator<<(std::ostream& _os, const Vector2& _vec)
{
	_os << "(" << _vec.x << ", " << _vec.y << ")";
}

// Returns true if both x, y are equal
bool Vector2::operator==(const Vector2& _other)
{
	return x == _other.x && y == _other.y;
}

// Returns true if any component is not equal
bool Vector2::operator!=(const Vector2& _other)
{
	return x != _other.x || y != _other.y;
}

// Returns component at _index, i.e. 0 => x
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

// Returns the magnitude of the vector
float Vector2::Magnitude() const
{
	return sqrtf(powf(x, 2) + powf(y, 2));
}

// Returns the magnitude of _vector
float Vector2::Magnitude(const Vector2& _vector)
{
	return sqrtf(powf(_vector.x, 2) + powf(_vector.y, 2));
}

// Returns the normalized vector
Vector2 Vector2::Normalized() const
{
	return *this / Magnitude();
}

// Returns _vector normalized
Vector2 Vector2::Normalized(const Vector2& _vector)
{
	return _vector / Magnitude(_vector);
}

// Normalizes this vector
void Vector2::Normalize()
{
	float magnitude = Magnitude();

	x /= magnitude;
	y /= magnitude;
}

// Gets the angle between this vector and _other vector
float Vector2::Angle(const Vector2& _other) const
{
	float totalMagnitude = Magnitude() * _other.Magnitude();
	float cosResult = Dot(_other) / (totalMagnitude);
	return HELPERS::Rad2Deg(acosf(cosResult));
}

// Gets the angle between _to and _from vectors
float Vector2::Angle(const Vector2& _to, const Vector2& _from)
{
	float totalMagnitude = Magnitude(_to) * Magnitude(_from);
	float cosResult = Dot(_to, _from) / (totalMagnitude);
	return HELPERS::Rad2Deg(acosf(cosResult));
}

// Gets the dot product of this and _other vectors
float Vector2::Dot(const Vector2& _other) const
{
	return (x * _other.x) + (y * _other.y);
}

// Gets the dot product of _a and _b vectors
float Vector2::Dot(const Vector2& _a, const Vector2& _b)
{
	return (_a.x * _b.x) + (_a.y * _b.y);
}

// Returns a vector lerped between _from, _to by _t
Vector2 Vector2::Lerp(const Vector2& _from, const Vector2& _to, float _t)
{
	float tClamp = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));
	return _from + (_to - _from) * tClamp;
}

// Gets the distance between _a and _b
float Vector2::Distance(const Vector2& _a, const Vector2& _b)
{
	return (_a - _b).Magnitude();
}

// Returns the _inDirection vector reflected over the _normal
Vector2 Vector2::Reflect(const Vector2& _inDirection, const Vector2& _normal)
{
	return _inDirection - 2.f * Dot(_inDirection, _normal) * _normal;
}