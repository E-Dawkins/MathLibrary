#include "pch.h"
#include "Matrix3x3.h"
#include "Vector3.h"
#include "Matrix2x2.h"

Matrix3x3 Matrix3x3::zero = Matrix3x3(0);
Matrix3x3 Matrix3x3::identity = Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1);

Matrix3x3::Matrix3x3()
{
	m_rows.push_back(Vector3(0));
	m_rows.push_back(Vector3(0));
	m_rows.push_back(Vector3(0));
}

Matrix3x3::Matrix3x3(float _value)
{
	m_rows.push_back(Vector3(_value));
	m_rows.push_back(Vector3(_value));
	m_rows.push_back(Vector3(_value));
}

Matrix3x3::Matrix3x3(float _m1, float _m2, float _m3, float _m4, 
	float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m_rows.push_back(Vector3(_m1, _m2, _m3));
	m_rows.push_back(Vector3(_m4, _m5, _m6));
	m_rows.push_back(Vector3(_m7, _m8, _m9));
}

Matrix3x3 Matrix3x3::operator + (Matrix3x3 _other)
{
	return Matrix3x3(
		m_rows[0][0] + _other[0][0], m_rows[0][1] + _other[0][1], m_rows[0][2] + _other[0][2],
		m_rows[1][0] + _other[1][0], m_rows[1][1] + _other[1][1], m_rows[1][2] + _other[1][2], 
		m_rows[2][0] + _other[2][0], m_rows[2][1] + _other[2][1], m_rows[2][2] + _other[2][2]
	);
}

Matrix3x3 Matrix3x3::operator + (float _value)
{
	return Matrix3x3(
		m_rows[0][0] + _value, m_rows[0][1] + _value, m_rows[0][2] + _value,
		m_rows[1][0] + _value, m_rows[1][1] + _value, m_rows[1][2] + _value,
		m_rows[2][0] + _value, m_rows[2][1] + _value, m_rows[2][2] + _value
	);
}

void Matrix3x3::operator += (Matrix3x3 _other)
{
	m_rows[0] += _other[0];
	m_rows[1] += _other[1];
	m_rows[2] += _other[2];
}

void Matrix3x3::operator += (float _value)
{
	m_rows[0] += _value;
	m_rows[1] += _value;
	m_rows[2] += _value;
}

Matrix3x3 Matrix3x3::operator - (Matrix3x3 _other)
{
	return Matrix3x3(
		m_rows[0][0] - _other[0][0], m_rows[0][1] - _other[0][1], m_rows[0][2] - _other[0][2],
		m_rows[1][0] - _other[1][0], m_rows[1][1] - _other[1][1], m_rows[1][2] - _other[1][2],
		m_rows[2][0] - _other[2][0], m_rows[2][1] - _other[2][1], m_rows[2][2] - _other[2][2]
	);
}

Matrix3x3 Matrix3x3::operator - (float _value)
{
	return Matrix3x3(
		m_rows[0][0] - _value, m_rows[0][1] - _value, m_rows[0][2] - _value,
		m_rows[1][0] - _value, m_rows[1][1] - _value, m_rows[1][2] - _value,
		m_rows[2][0] - _value, m_rows[2][1] - _value, m_rows[2][2] - _value
	);
}

void Matrix3x3::operator -= (Matrix3x3 _other)
{
	m_rows[0] -= _other[0];
	m_rows[1] -= _other[1];
	m_rows[2] -= _other[2];
}

void Matrix3x3::operator -= (float _value)
{
	m_rows[0] -= _value;
	m_rows[1] -= _value;
	m_rows[2] -= _value;
}

Matrix3x3 operator * (float _multi, Matrix3x3 _mat)
{
	return Matrix3x3
	(
		_mat[0][0] * _multi, _mat[0][1] * _multi, _mat[0][2] * _multi,
		_mat[1][0] * _multi, _mat[1][1] * _multi, _mat[1][2] * _multi,
		_mat[2][0] * _multi, _mat[2][1] * _multi, _mat[2][2] * _multi
	);
}

Matrix3x3 operator * (Matrix3x3 _mat, float _multi)
{
	return Matrix3x3
	(
		_mat[0][0] * _multi, _mat[0][1] * _multi, _mat[0][2] * _multi,
		_mat[1][0] * _multi, _mat[1][1] * _multi, _mat[1][2] * _multi,
		_mat[2][0] * _multi, _mat[2][1] * _multi, _mat[2][2] * _multi
	);
}

void Matrix3x3::operator *= (float _multi)
{
	m_rows[0] *= _multi;
	m_rows[1] *= _multi;
	m_rows[2] *= _multi;
}

Matrix3x3 operator * (Matrix3x3 _a, Matrix3x3 _b)
{
	float m1 = (_a[0][0] * _b[0][0]) + (_a[0][1] * _b[1][0]) + (_a[0][2] * _b[2][0]);
	float m2 = (_a[0][0] * _b[0][1]) + (_a[0][1] * _b[1][1]) + (_a[0][2] * _b[2][1]);
	float m3 = (_a[0][0] * _b[0][2]) + (_a[0][1] * _b[1][2]) + (_a[0][2] * _b[2][2]);

	float m4 = (_a[1][0] * _b[0][0]) + (_a[1][1] * _b[1][0]) + (_a[1][2] * _b[2][0]);
	float m5 = (_a[1][0] * _b[0][1]) + (_a[1][1] * _b[1][1]) + (_a[1][2] * _b[2][1]);
	float m6 = (_a[1][0] * _b[0][2]) + (_a[1][1] * _b[1][2]) + (_a[1][2] * _b[2][2]);

	float m7 = (_a[2][0] * _b[0][0]) + (_a[2][1] * _b[1][0]) + (_a[2][2] * _b[2][0]);
	float m8 = (_a[2][0] * _b[0][1]) + (_a[2][1] * _b[1][1]) + (_a[2][2] * _b[2][1]);
	float m9 = (_a[2][0] * _b[0][2]) + (_a[2][1] * _b[1][2]) + (_a[2][2] * _b[2][2]);

	return Matrix3x3(m1, m2, m3, m4, m5, m6, m7, m8, m9);
}

Vector3 operator * (Matrix3x3 _mat, Vector3 _vec)
{
	float v1 = (_mat[0][0] * _vec[0]) + (_mat[0][1] * _vec[1]) + (_mat[0][2] * _vec[2]);
	float v2 = (_mat[1][0] * _vec[0]) + (_mat[1][1] * _vec[1]) + (_mat[1][2] * _vec[2]);
	float v3 = (_mat[2][0] * _vec[0]) + (_mat[2][1] * _vec[1]) + (_mat[2][2] * _vec[2]);
	return Vector3(v1, v2, v3);
}

Vector3 operator * (Vector3 _vec, Matrix3x3 _mat)
{
	float v1 = (_vec[0] * _mat[0][0]) + (_vec[1] * _mat[1][0]) + (_vec[2] * _mat[2][0]);
	float v2 = (_vec[0] * _mat[0][1]) + (_vec[1] * _mat[1][1]) + (_vec[2] * _mat[2][1]);
	float v3 = (_vec[0] * _mat[0][2]) + (_vec[1] * _mat[1][2]) + (_vec[2] * _mat[2][2]);
	return Vector3(v1, v2, v3);
}

Matrix3x3 operator / (Matrix3x3 _mat, float _div)
{
	return Matrix3x3
	(
		_mat[0][0] / _div, _mat[0][1] / _div, _mat[0][2] / _div,
		_mat[1][0] / _div, _mat[1][1] / _div, _mat[1][2] / _div,
		_mat[2][0] / _div, _mat[2][1] / _div, _mat[2][2] / _div
	);
}

void Matrix3x3::operator /= (float _div)
{
	m_rows[0] /= _div;
	m_rows[1] /= _div;
	m_rows[2] /= _div;
}

Vector3& Matrix3x3::operator[](int _row)
{
	return m_rows[_row];
}

float& Matrix3x3::operator()(int _row, int _index)
{
	return m_rows[_row][_index];
}

bool Matrix3x3::operator==(Matrix3x3 _other)
{
	return m_rows[0] == _other[0] && m_rows[1] == _other[1] && m_rows[2] == _other[2];
}

bool Matrix3x3::operator!=(Matrix3x3 _other)
{
	return m_rows[0] != _other[0] || m_rows[1] != _other[1] || m_rows[2] != _other[2];
}

void operator << (std::ostream& _os, Matrix3x3& _mat)
{
	_os << "(" << _mat[0][0] << ", " << _mat[0][1] << ", " << _mat[0][2] << ", " << _mat[1][0] << ", " << _mat[1][1] 
		<< ", " << _mat[1][2] << ", " << _mat[2][0] << ", " << _mat[2][1] << ", " << _mat[2][2] << ")";
}

Vector3& Matrix3x3::GetRow(int _row)
{
	return m_rows[_row];
}

Vector3 Matrix3x3::GetCol(int _col)
{
	return Vector3(m_rows[0][_col], m_rows[1][_col], m_rows[2][_col]);
}

bool Matrix3x3::IsIdentity()
{
	return (*this) == Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

bool Matrix3x3::IsIdentity(Matrix3x3 _mat)
{
	return _mat == Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

float Matrix3x3::Determinant()
{
	Matrix2x2 aMat = Matrix2x2(m_rows[1][1], m_rows[1][2], m_rows[2][1], m_rows[2][2]);
	Matrix2x2 bMat = Matrix2x2(m_rows[1][0], m_rows[1][2], m_rows[2][0], m_rows[2][2]);
	Matrix2x2 cMat = Matrix2x2(m_rows[1][0], m_rows[1][1], m_rows[2][0], m_rows[2][1]);

	float a = m_rows[0][0];
	float b = m_rows[0][1];
	float c = m_rows[0][2];

	return (a * aMat.Determinant()) - (b * bMat.Determinant()) + (c * cMat.Determinant());
}

float Matrix3x3::Determinant(Matrix3x3 _mat)
{
	Matrix2x2 aMat = Matrix2x2(_mat[1][1], _mat[1][2], _mat[2][1], _mat[2][2]);
	Matrix2x2 bMat = Matrix2x2(_mat[1][0], _mat[1][2], _mat[2][0], _mat[2][2]);
	Matrix2x2 cMat = Matrix2x2(_mat[1][0], _mat[1][1], _mat[2][0], _mat[2][1]);

	float a = _mat[0][0];
	float b = _mat[0][1];
	float c = _mat[0][2];

	return (a * aMat.Determinant()) - (b * bMat.Determinant()) + (c * cMat.Determinant());
}
