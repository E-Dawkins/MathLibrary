#include "pch.h"
#include "Vector4.h"
#include "Helpers.h"

// Shorthand for Vector4(0, 0, 0, 0)
Vector4 Vector4::zero = Vector4(0);

// Shorthand for Vector4(1, 1, 1, 1)
Vector4 Vector4::one = Vector4(1);

// Shorthand for Vector4(0.5, 0.5, 0.5, 0.5)
Vector4 Vector4::half = Vector4(0.5f);

// Construct vector(0, 0, 0, 0)
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

// Construct vector(_value, _value, _value, _value)
Vector4::Vector4(float _value)
{
	x = _value;
	y = _value;
	z = _value;
	w = _value;
}

// Construct vector(_x, _y, _z, _w)
Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

// Adds two vectors component wise
Vector4 Vector4::operator+(const Vector4& _other) const
{
	return Vector4(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}

// Adds _value to each component
Vector4 Vector4::operator+(float _value) const
{
	return Vector4(x + _value, y + _value, z + _value, w + _value);
}

// Adds _other to this
void Vector4::operator+=(const Vector4& _other)
{
	x += _other.x;
	y += _other.y;
	z += _other.z;
	w += _other.w;
}

// Adds _value to this
void Vector4::operator+=(float _value)
{
	x += _value;
	y += _value;
	z += _value;
	w += _value;
}

// Subtracts two vectors component wise
Vector4 Vector4::operator-(const Vector4& _other) const
{
	return Vector4(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}

// Subtracts _value from each component
Vector4 Vector4::operator-(float _value) const
{
	return Vector4(x - _value, y - _value, z - _value, w - _value);
}

// Subtracts _other from this
void Vector4::operator-=(const Vector4& _other)
{
	x -= _other.x;
	y -= _other.y;
	z -= _other.z;
	w -= _other.w;
}

// Subtracts _value from this
void Vector4::operator-=(float _value)
{
	x -= _value;
	y -= _value;
	z -= _value;
	w -= _value;
}

// Multiplies this by _multiplier
void Vector4::operator*=(float _multiplier)
{
	x *= _multiplier;
	y *= _multiplier;
	z *= _multiplier;
	w *= _multiplier;
}

// Multiplies _vec by _multi component wise
Vector4 operator*(float _multi, const Vector4& _vec)
{
	return Vector4(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi, _vec.w * _multi);
}

// Multiplies _vec by _multi component wise
Vector4 operator*(const Vector4& _vec, float _multi)
{
	return Vector4(_vec.x * _multi, _vec.y * _multi, _vec.z * _multi, _vec.w * _multi);
}

// Divides this by _divisor component wise
Vector4 Vector4::operator/(float _divisor) const
{
	return Vector4(x / _divisor, y / _divisor, z / _divisor, w / _divisor);
}

// Divides this by _divisor component wise
void Vector4::operator/=(float _divisor)
{
	x /= _divisor;
	y /= _divisor;
	z /= _divisor;
	w /= _divisor;
}

// Appends (x, y, z, w) to _os
void operator<<(std::ostream& _os, const Vector4& _vector)
{
	_os << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ", " << _vector.w << ")";
}

// Returns true if every component == _other
bool Vector4::operator==(const Vector4& _other)
{
	return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}

// Returns true if any component != _other
bool Vector4::operator!=(const Vector4& _other)
{
	return x != _other.x || y != _other.y || z != _other.z || w != _other.w;
}

// Returns component at _index, i.e 0 => x
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

// Gets magnitude of this
float Vector4::Magnitude() const
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2) + powf(w, 2));
}

// Gets magnitude of _vector
float Vector4::Magnitude(const Vector4& _vector)
{
	return sqrtf(powf(_vector.x, 2) + powf(_vector.y, 2) + powf(_vector.z, 2) + powf(_vector.w, 2));
}

// Gets this normalized
Vector4 Vector4::Normalized() const
{
	return *this / Magnitude();
}

// Gets _vector normalized
Vector4 Vector4::Normalized(const Vector4& _vector)
{
	return _vector / Magnitude(_vector);
}

// Normalizes this vector
void Vector4::Normalize()
{
	float magnitude = Magnitude();

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
	w /= magnitude;
}

// Gets dot product of this and _other
float Vector4::Dot(const Vector4& _other) const
{
	return (x * _other.x) + (y * _other.y) + (z * _other.z) + (w * _other.w);
}

// Gets dot product of _a and _b
float Vector4::Dot(const Vector4& _a, const Vector4& _b)
{
	return (_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z) + (_a.w * _b.w);
}

// Lerps inbetween _from, _to by _t
Vector4 Vector4::Lerp(const Vector4& _from, const Vector4& _to, float _t)
{
	float tClamp = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));
	return _from + (_to - _from) * tClamp;
}

// Gets distance between _a and _b
float Vector4::Distance(const Vector4& _a, const Vector4& _b)
{
	return (_a - _b).Magnitude();
}