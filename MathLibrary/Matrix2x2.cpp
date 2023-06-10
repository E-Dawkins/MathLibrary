#include "pch.h"
#include "Matrix2x2.h"

Matrix2x2 Matrix2x2::zero = Matrix2x2(0);
Matrix2x2 Matrix2x2::identity = Matrix2x2(1, 0, 0, 1);

Matrix2x2::Matrix2x2()
{
	m_rows.push_back(Vector2(0));
	m_rows.push_back(Vector2(0));
}

Matrix2x2::Matrix2x2(float _value)
{
	m_rows.push_back(Vector2(_value));
	m_rows.push_back(Vector2(_value));
}

Matrix2x2::Matrix2x2(float _m1, float _m2, float _m3, float _m4)
{
	m_rows.push_back(Vector2(_m1, _m2));
	m_rows.push_back(Vector2(_m3, _m4));
}

Matrix2x2 Matrix2x2::operator+(Matrix2x2 _other)
{
	return Matrix2x2((*this)[0][0] + _other[0][0], (*this)[0][1] + _other[0][1], 
					(*this)[1][0] + _other[1][0], (*this)[1][1] + _other[1][1]);
}

Matrix2x2 Matrix2x2::operator+(float _value)
{
	return Matrix2x2((*this)[0][0] + _value, (*this)[0][1] + _value, 
					(*this)[1][0] + _value, (*this)[1][1] + _value);
}

void Matrix2x2::operator+=(Matrix2x2 _other)
{
	(*this)[0] += _other[0];
	(*this)[1] += _other[1];
}

void Matrix2x2::operator+=(float _value)
{
	(*this)[0] += _value;
	(*this)[1] += _value;
}

Matrix2x2 Matrix2x2::operator-(Matrix2x2 _other)
{
	return Matrix2x2((*this)[0][0] - _other[0][0], (*this)[0][1] - _other[0][1],
					(*this)[1][0] - _other[1][0], (*this)[1][1] - _other[1][1]);
}

Matrix2x2 Matrix2x2::operator-(float _value)
{
	return Matrix2x2((*this)[0][0] - _value, (*this)[0][1] - _value,
					(*this)[1][0] - _value, (*this)[1][1] - _value);
}

void Matrix2x2::operator-=(Matrix2x2 _other)
{
	(*this)[0] -= _other[0];
	(*this)[1] -= _other[1];
}

void Matrix2x2::operator-=(float _value)
{
	(*this)[0] -= _value;
	(*this)[1] -= _value;
}

Matrix2x2 operator*(float _multi, Matrix2x2 _mat)
{
	return Matrix2x2(_mat[0][0] * _multi, _mat[0][1] * _multi, _mat[1][0] * _multi, _mat[1][1] * _multi);
}

Matrix2x2 operator*(Matrix2x2 _mat, float _multi)
{
	return Matrix2x2(_mat[0][0] * _multi, _mat[0][1] * _multi, _mat[1][0] * _multi, _mat[1][1] * _multi);
}

Matrix2x2 operator*(Matrix2x2 _a, Matrix2x2 _b)
{
	float m1 = (_a[0][0] * _b[0][0]) + (_a[0][1] * _b[1][0]);
	float m2 = (_a[0][0] * _b[0][1]) + (_a[0][1] * _b[1][1]);
	float m3 = (_a[1][0] * _b[0][0]) + (_a[1][1] * _b[1][0]);
	float m4 = (_a[1][0] * _b[0][1]) + (_a[1][1] * _b[1][1]);
	return Matrix2x2(m1, m2, m3, m4);
}

Vector2 operator*(Matrix2x2 _mat, Vector2 _vec)
{
	float v1 = (_mat[0][0] * _vec[0]) + (_mat[0][1] * _vec[1]);
	float v2 = (_mat[1][0] * _vec[0]) + (_mat[1][1] * _vec[1]);
	return Vector2(v1, v2);
}

Vector2 operator*(Vector2 _vec, Matrix2x2 _mat)
{
	float v1 = (_vec[0] * _mat[0][0]) + (_vec[1] * _mat[1][0]);
	float v2 = (_vec[0] * _mat[0][1]) + (_vec[1] * _mat[1][1]);
	return Vector2(v1, v2);
}

Matrix2x2 operator/(Matrix2x2 _mat, float _div)
{
	return Matrix2x2(_mat[0][0] / _div, _mat[0][1] / _div, _mat[1][0] / _div, _mat[1][1] / _div);
}

void Matrix2x2::operator*=(float _multi)
{
	m_rows[0] *= _multi;
	m_rows[1] *= _multi;
}

void Matrix2x2::operator/=(float _div)
{
	m_rows[0] /= _div;
	m_rows[1] /= _div;
}

Vector2& Matrix2x2::operator[](int _row)
{
	return m_rows[_row];
}

float& Matrix2x2::operator()(int _row, int _col)
{
	return m_rows[_row][_col];
}

bool Matrix2x2::operator==(Matrix2x2 _other)
{
	return (m_rows[0] == _other[0] && m_rows[1] == _other[1]);
}

bool Matrix2x2::operator!=(Matrix2x2 _other)
{
	return (m_rows[0] != _other[0] || m_rows[1] != _other[1]);
}

void operator<<(std::ostream& _os, Matrix2x2& _mat)
{
	_os << "(" << _mat[0][0] << ", " << _mat[0][1] << ", " << _mat[1][0] << ", " << _mat[1][1] << ")";
}

Vector2& Matrix2x2::GetRow(int _row)
{
	return m_rows[_row];
}

Vector2 Matrix2x2::GetCol(int _col)
{
	return Vector2(m_rows[0][_col], m_rows[1][_col]);
}

bool Matrix2x2::IsIdentity()
{
	return (*this) == Matrix2x2(1, 0, 0, 1);
}

bool Matrix2x2::IsIdentity(Matrix2x2 _mat)
{
	return _mat == Matrix2x2(1, 0, 0, 1);
}

float Matrix2x2::Determinant()
{
	return (m_rows[0][0] * m_rows[1][1]) - (m_rows[0][1] * m_rows[1][0]);
}

float Matrix2x2::Determinant(Matrix2x2 _mat)
{
	return (_mat[0][0] * _mat[1][1]) - (_mat[0][1] * _mat[1][0]);
}

Matrix2x2 Matrix2x2::Inverse()
{
	return Matrix2x2(m_rows[1][1], -m_rows[0][1], -m_rows[1][0], m_rows[0][0]) / Determinant();
}

Matrix2x2 Matrix2x2::Inverse(Matrix2x2 _mat)
{
	return Matrix2x2(_mat[1][1], -_mat[0][1], -_mat[1][0], _mat[0][0]) / Determinant(_mat);
}

Matrix2x2 Matrix2x2::Transpose()
{
	return Matrix2x2(m_rows[0][0], m_rows[1][0], m_rows[0][1], m_rows[1][1]);
}

Matrix2x2 Matrix2x2::Transpose(Matrix2x2 _mat)
{
	return Matrix2x2(_mat[0][0], _mat[1][0], _mat[0][1], _mat[1][1]);
}
