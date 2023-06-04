#include "pch.h"
#include "Matrix2x2.h"
#include "Vector2.h"

Matrix2x2 Matrix2x2::zero = Matrix2x2(0);
Matrix2x2 Matrix2x2::identity = Matrix2x2(1, 0, 0, 1);

Matrix2x2::Matrix2x2()
{
	m1 = 0;
	m2 = 0;
	m3 = 0;
	m4 = 0;
}

Matrix2x2::Matrix2x2(float _value)
{
	m1 = _value;
	m2 = _value;
	m3 = _value;
	m4 = _value;
}

Matrix2x2::Matrix2x2(float _m1, float _m2, float _m3, float _m4)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
}

Matrix2x2 Matrix2x2::operator+(Matrix2x2 _other)
{
	return Matrix2x2(m1 + _other.m1, m2 + _other.m2, m3 + _other.m3, m4 + _other.m4);
}

Matrix2x2 Matrix2x2::operator+(float _value)
{
	return Matrix2x2(m1 + _value, m2 + _value, m3 + _value, m4 + _value);
}

void Matrix2x2::operator+=(Matrix2x2 _other)
{
	m1 += _other.m1;
	m2 += _other.m2;
	m3 += _other.m3;
	m4 += _other.m4;
}

void Matrix2x2::operator+=(float _value)
{
	m1 += _value;
	m2 += _value;
	m3 += _value;
	m4 += _value;
}

Matrix2x2 Matrix2x2::operator-(Matrix2x2 _other)
{
	return Matrix2x2(m1 - _other.m1, m2 - _other.m2, m3 - _other.m3, m4 - _other.m4);
}

Matrix2x2 Matrix2x2::operator-(float _value)
{
	return Matrix2x2(m1 - _value, m2 - _value, m3 - _value, m4 - _value);
}

void Matrix2x2::operator-=(Matrix2x2 _other)
{
	m1 -= _other.m1;
	m2 -= _other.m2;
	m3 -= _other.m3;
	m4 -= _other.m4;
}

void Matrix2x2::operator-=(float _value)
{
	m1 -= _value;
	m2 -= _value;
	m3 -= _value;
	m4 -= _value;
}

Matrix2x2 operator*(float _multi, Matrix2x2 _mat)
{
	return Matrix2x2(_mat.m1 * _multi, _mat.m2 * _multi, _mat.m3 * _multi, _mat.m4 * _multi);
}

Matrix2x2 operator*(Matrix2x2 _mat, float _multi)
{
	return Matrix2x2(_mat.m1 * _multi, _mat.m2 * _multi, _mat.m3 * _multi, _mat.m4 * _multi);
}

Matrix2x2 operator*(Matrix2x2 _a, Matrix2x2 _b)
{
	float m1 = (_a.m1 * _b.m1) + (_a.m2 * _b.m3);
	float m2 = (_a.m1 * _b.m2) + (_a.m2 * _b.m4);
	float m3 = (_a.m3 * _b.m1) + (_a.m4 * _b.m3);
	float m4 = (_a.m3 * _b.m2) + (_a.m4 * _b.m4);
	return Matrix2x2(m1, m2, m3, m4);
}

Vector2 operator*(Matrix2x2 _mat, Vector2 _vec)
{
	float v1 = (_mat.m1 * _vec.x) + (_mat.m2 * _vec.y);
	float v2 = (_mat.m3 * _vec.x) + (_mat.m4 * _vec.y);
	return Vector2(v1, v2);
}

Vector2 operator*(Vector2 _vec, Matrix2x2 _mat)
{
	float v1 = (_mat.m1 * _vec.x) + (_mat.m2 * _vec.y);
	float v2 = (_mat.m3 * _vec.x) + (_mat.m4 * _vec.y);
	return Vector2(v1, v2);
}

Matrix2x2 operator/(float _div, Matrix2x2 _mat)
{
	return Matrix2x2(_mat.m1 / _div, _mat.m2 / _div, _mat.m3 / _div, _mat.m4 / _div);
}

Matrix2x2 operator/(Matrix2x2 _mat, float _div)
{
	return Matrix2x2(_mat.m1 / _div, _mat.m2 / _div, _mat.m3 / _div, _mat.m4 / _div);
}

void Matrix2x2::operator*=(float _multi)
{
	m1 *= _multi;
	m2 *= _multi;
	m3 *= _multi;
	m4 *= _multi;
}

void Matrix2x2::operator/=(float _div)
{
	m1 /= _div;
	m2 /= _div;
	m3 /= _div;
	m4 /= _div;
}

Matrix2x2 Matrix2x2::Inverse()
{
	return Matrix2x2();
}

Matrix2x2 Matrix2x2::Inverse(Matrix2x2 _mat)
{
	return Matrix2x2();
}
