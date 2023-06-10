#include "pch.h"
#include "Matrix4x4.h"
#include "Matrix3x3.h"
#include "Helpers.h"

using namespace HELPERS;

// Shorthand of zeroed matrix
Matrix4x4 Matrix4x4::zero = Matrix4x4(0);

// Shorthand for Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1)
Matrix4x4 Matrix4x4::identity = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

// Constructs zeroed matrix
Matrix4x4::Matrix4x4()
{
	m_rows.push_back(Vector4(0));
	m_rows.push_back(Vector4(0));
	m_rows.push_back(Vector4(0));
	m_rows.push_back(Vector4(0));
}

// Constructs matrix with every component = _value
Matrix4x4::Matrix4x4(float _value)
{
	m_rows.push_back(Vector4(_value));
	m_rows.push_back(Vector4(_value));
	m_rows.push_back(Vector4(_value));
	m_rows.push_back(Vector4(_value));
}

// Constructs matrix where component = respective value
Matrix4x4::Matrix4x4(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, 
	float _m9, float _m10, float _m11, float _m12, float _m13, float _m14, float _m15, float _m16)
{
	m_rows.push_back(Vector4(_m1, _m2, _m3, _m4));
	m_rows.push_back(Vector4(_m5, _m6, _m7, _m8));
	m_rows.push_back(Vector4(_m9, _m10, _m11, _m12));
	m_rows.push_back(Vector4(_m13, _m14, _m15, _m16));
}

// Adds two matrices component wise
Matrix4x4 Matrix4x4::operator+(Matrix4x4 _other)
{
	return Matrix4x4(
		m_rows[0][0] + _other[0][0], m_rows[0][1] + _other[0][1], m_rows[0][2] + _other[0][2], m_rows[0][3] + _other[0][3],
		m_rows[1][0] + _other[1][0], m_rows[1][1] + _other[1][1], m_rows[1][2] + _other[1][2], m_rows[1][3] + _other[1][3],
		m_rows[2][0] + _other[2][0], m_rows[2][1] + _other[2][1], m_rows[2][2] + _other[2][2], m_rows[2][3] + _other[2][3],
		m_rows[3][0] + _other[3][0], m_rows[3][1] + _other[3][1], m_rows[3][2] + _other[3][2], m_rows[3][3] + _other[3][3]
	);
}

// Adds _value to each component
Matrix4x4 Matrix4x4::operator+(float _value)
{
	return Matrix4x4(
		m_rows[0][0] + _value, m_rows[0][1] + _value, m_rows[0][2] + _value, m_rows[0][3] + _value,
		m_rows[1][0] + _value, m_rows[1][1] + _value, m_rows[1][2] + _value, m_rows[1][3] + _value,
		m_rows[2][0] + _value, m_rows[2][1] + _value, m_rows[2][2] + _value, m_rows[2][3] + _value,
		m_rows[3][0] + _value, m_rows[3][1] + _value, m_rows[3][2] + _value, m_rows[3][3] + _value
		);
}

// Adds _other to this
void Matrix4x4::operator+=(Matrix4x4 _other)
{
	m_rows[0] += _other[0];
	m_rows[1] += _other[1];
	m_rows[2] += _other[2];
	m_rows[3] += _other[3];
}

// Adds _value to this
void Matrix4x4::operator+=(float _value)
{
	m_rows[0] += _value;
	m_rows[1] += _value;
	m_rows[2] += _value;
	m_rows[3] += _value;
}

// Subtracts two matrices component wise
Matrix4x4 Matrix4x4::operator-(Matrix4x4 _other)
{
	return Matrix4x4(
		m_rows[0][0] - _other[0][0], m_rows[0][1] - _other[0][1], m_rows[0][2] - _other[0][2], m_rows[0][3] - _other[0][3],
		m_rows[1][0] - _other[1][0], m_rows[1][1] - _other[1][1], m_rows[1][2] - _other[1][2], m_rows[1][3] - _other[1][3],
		m_rows[2][0] - _other[2][0], m_rows[2][1] - _other[2][1], m_rows[2][2] - _other[2][2], m_rows[2][3] - _other[2][3],
		m_rows[3][0] - _other[3][0], m_rows[3][1] - _other[3][1], m_rows[3][2] - _other[3][2], m_rows[3][3] - _other[3][3]
	);
}

// Subtracts each component by _value
Matrix4x4 Matrix4x4::operator-(float _value)
{
	return Matrix4x4(
		m_rows[0][0] - _value, m_rows[0][1] - _value, m_rows[0][2] - _value, m_rows[0][3] - _value,
		m_rows[1][0] - _value, m_rows[1][1] - _value, m_rows[1][2] - _value, m_rows[1][3] - _value,
		m_rows[2][0] - _value, m_rows[2][1] - _value, m_rows[2][2] - _value, m_rows[2][3] - _value,
		m_rows[3][0] - _value, m_rows[3][1] - _value, m_rows[3][2] - _value, m_rows[3][3] - _value
	);
}

// Subtracts _other from this
void Matrix4x4::operator-=(Matrix4x4 _other)
{
	m_rows[0] -= _other[0];
	m_rows[1] -= _other[1];
	m_rows[2] -= _other[2];
	m_rows[3] -= _other[3];
}

// Subtracts _value from this
void Matrix4x4::operator-=(float _value)
{
	m_rows[0] -= _value;
	m_rows[1] -= _value;
	m_rows[2] -= _value;
	m_rows[3] -= _value;
}

// Multiplies each _mat component by _multi
Matrix4x4 operator * (float _multi, Matrix4x4 _mat)
{
	return Matrix4x4(
		_mat[0][0] * _multi, _mat[0][1] * _multi, _mat[0][2] * _multi, _mat[0][3] * _multi,
		_mat[1][0] * _multi, _mat[1][1] * _multi, _mat[1][2] * _multi, _mat[1][3] * _multi,
		_mat[2][0] * _multi, _mat[2][1] * _multi, _mat[2][2] * _multi, _mat[2][3] * _multi,
		_mat[3][0] * _multi, _mat[3][1] * _multi, _mat[3][2] * _multi, _mat[3][3] * _multi
	);
}

// Multiplies each _mat component by _multi
Matrix4x4 operator*(Matrix4x4 _mat, float _multi)
{
	return Matrix4x4(
		_mat[0][0] * _multi, _mat[0][1] * _multi, _mat[0][2] * _multi, _mat[0][3] * _multi,
		_mat[1][0] * _multi, _mat[1][1] * _multi, _mat[1][2] * _multi, _mat[1][3] * _multi,
		_mat[2][0] * _multi, _mat[2][1] * _multi, _mat[2][2] * _multi, _mat[2][3] * _multi,
		_mat[3][0] * _multi, _mat[3][1] * _multi, _mat[3][2] * _multi, _mat[3][3] * _multi
	);
}

// Perform matrix multiplication on _a and _b
Matrix4x4 operator*(Matrix4x4 _a, Matrix4x4 _b)
{
	float m1 = (_a[0][0] * _b[0][0]) + (_a[0][1] * _b[1][0]) + (_a[0][2] * _b[2][0]) + (_a[0][3] * _b[3][0]);
	float m2 = (_a[0][0] * _b[0][1]) + (_a[0][1] * _b[1][1]) + (_a[0][2] * _b[2][1]) + (_a[0][3] * _b[3][1]);
	float m3 = (_a[0][0] * _b[0][2]) + (_a[0][1] * _b[1][2]) + (_a[0][2] * _b[2][2]) + (_a[0][3] * _b[3][2]);
	float m4 = (_a[0][0] * _b[0][3]) + (_a[0][1] * _b[1][3]) + (_a[0][2] * _b[2][3]) + (_a[0][3] * _b[3][3]);

	float m5 = (_a[1][0] * _b[0][0]) + (_a[1][1] * _b[1][0]) + (_a[1][2] * _b[2][0]) + (_a[1][3] * _b[3][0]);
	float m6 = (_a[1][0] * _b[0][1]) + (_a[1][1] * _b[1][1]) + (_a[1][2] * _b[2][1]) + (_a[1][3] * _b[3][1]);
	float m7 = (_a[1][0] * _b[0][2]) + (_a[1][1] * _b[1][2]) + (_a[1][2] * _b[2][2]) + (_a[1][3] * _b[3][2]);
	float m8 = (_a[1][0] * _b[0][3]) + (_a[1][1] * _b[1][3]) + (_a[1][2] * _b[2][3]) + (_a[1][3] * _b[3][3]);

	float m9 = (_a[2][0] * _b[0][0]) + (_a[2][1] * _b[1][0]) + (_a[2][2] * _b[2][0]) + (_a[2][3] * _b[3][0]);
	float m10 = (_a[2][0] * _b[0][1]) + (_a[2][1] * _b[1][1]) + (_a[2][2] * _b[2][1]) + (_a[2][3] * _b[3][1]);
	float m11 = (_a[2][0] * _b[0][2]) + (_a[2][1] * _b[1][2]) + (_a[2][2] * _b[2][2]) + (_a[2][3] * _b[3][2]);
	float m12 = (_a[2][0] * _b[0][3]) + (_a[2][1] * _b[1][3]) + (_a[2][2] * _b[2][3]) + (_a[2][3] * _b[3][3]);

	float m13 = (_a[3][0] * _b[0][0]) + (_a[3][1] * _b[1][0]) + (_a[3][2] * _b[2][0]) + (_a[3][3] * _b[3][0]);
	float m14 = (_a[3][0] * _b[0][1]) + (_a[3][1] * _b[1][1]) + (_a[3][2] * _b[2][1]) + (_a[3][3] * _b[3][1]);
	float m15 = (_a[3][0] * _b[0][2]) + (_a[3][1] * _b[1][2]) + (_a[3][2] * _b[2][2]) + (_a[3][3] * _b[3][2]);
	float m16 = (_a[3][0] * _b[0][3]) + (_a[3][1] * _b[1][3]) + (_a[3][2] * _b[2][3]) + (_a[3][3] * _b[3][3]);

	return Matrix4x4(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16);
}

// Perform matrix multiplication on _mat and _vec
Vector4 operator*(Matrix4x4 _mat, Vector4 _vec)
{
	float v1 = (_mat[0][0] * _vec[0]) + (_mat[0][1] * _vec[1]) + (_mat[0][2] * _vec[2]) + (_mat[0][3] * _vec[3]);
	float v2 = (_mat[1][0] * _vec[0]) + (_mat[1][1] * _vec[1]) + (_mat[1][2] * _vec[2]) + (_mat[1][3] * _vec[3]);
	float v3 = (_mat[2][0] * _vec[0]) + (_mat[2][1] * _vec[1]) + (_mat[2][2] * _vec[2]) + (_mat[2][3] * _vec[3]);
	float v4 = (_mat[3][0] * _vec[0]) + (_mat[3][1] * _vec[1]) + (_mat[3][2] * _vec[2]) + (_mat[3][3] * _vec[3]);

	return Vector4(v1, v2, v3, v4);
}

// Perform matrix multiplication on _vec and _mat
Vector4 operator*(Vector4 _vec, Matrix4x4 _mat)
{
	float v1 = (_vec[0] * _mat[0][0]) + (_vec[1] * _mat[1][0]) + (_vec[2] * _mat[2][0]) + (_vec[3] * _mat[3][0]);
	float v2 = (_vec[0] * _mat[0][1]) + (_vec[1] * _mat[1][1]) + (_vec[2] * _mat[2][1]) + (_vec[3] * _mat[3][1]);
	float v3 = (_vec[0] * _mat[0][2]) + (_vec[1] * _mat[1][2]) + (_vec[2] * _mat[2][2]) + (_vec[3] * _mat[3][2]);
	float v4 = (_vec[0] * _mat[0][3]) + (_vec[1] * _mat[1][3]) + (_vec[2] * _mat[2][3]) + (_vec[3] * _mat[3][3]);

	return Vector4(v1, v2, v3, v4);
}

// Multiplies each component by _multi
void Matrix4x4::operator*=(float _multi)
{
	m_rows[0] *= _multi;
	m_rows[1] *= _multi;
	m_rows[2] *= _multi;
	m_rows[3] *= _multi;
}

// Divides each _mat component by _div
Matrix4x4 operator / (Matrix4x4 _mat, float _div)
{
	return Matrix4x4
	(
		_mat[0][0] / _div, _mat[0][1] / _div, _mat[0][2] / _div, _mat[0][3] / _div,
		_mat[1][0] / _div, _mat[1][1] / _div, _mat[1][2] / _div, _mat[1][3] / _div,
		_mat[2][0] / _div, _mat[2][1] / _div, _mat[2][2] / _div, _mat[2][3] / _div,
		_mat[3][0] / _div, _mat[3][1] / _div, _mat[3][2] / _div, _mat[3][3] / _div
	);
}

// Divides each component by _div
void Matrix4x4::operator/=(float _div)
{
	m_rows[0] /= _div;
	m_rows[1] /= _div;
	m_rows[2] /= _div;
	m_rows[3] /= _div;
}

// Gets row at _index
Vector4& Matrix4x4::operator[](int _index)
{
	return m_rows[_index];
}

// Gets component at (_row, _col)
float& Matrix4x4::operator()(int _row, int _col)
{
	return m_rows[_row][_col];
}

// Returns true if every component = _other
bool Matrix4x4::operator==(Matrix4x4 _other)
{
	return m_rows[0] == _other[0] && m_rows[1] == _other[1] &&
		m_rows[2] == _other[2] && m_rows[3] == _other[3];
}

// Returns true if any component != _other
bool Matrix4x4::operator!=(Matrix4x4 _other)
{
	return m_rows[0] != _other[0] || m_rows[1] != _other[1] ||
		m_rows[2] != _other[2] || m_rows[3] != _other[3];
}

// Appends _mat to _os
void operator<<(std::ostream& _os, Matrix4x4& _mat)
{
	_os << "(" << _mat[0][0] << ", " << _mat[0][1] << ", " << _mat[0][2] << ", " << _mat[0][3] <<
		", " << _mat[1][0] << ", " << _mat[1][1] << ", " << _mat[1][2] << ", " << _mat[1][3] <<
		", " << _mat[2][0] << ", " << _mat[2][1] << ", " << _mat[2][2] << ", " << _mat[2][3] <<
		", " << _mat[3][0] << ", " << _mat[3][1] << ", " << _mat[3][2] << ", " << _mat[3][3] << ")";
}

// Gets row at _row
Vector4& Matrix4x4::GetRow(int _row)
{
	return m_rows[_row];
}

// Gets column at _col
Vector4 Matrix4x4::GetCol(int _col)
{
	return Vector4(m_rows[0][_col], m_rows[1][_col],
		m_rows[2][_col], m_rows[3][_col]);
}

// Is this matrix = identity matrix
bool Matrix4x4::IsIdentity()
{
	return m_rows[0] == Vector4(1, 0, 0, 0) && m_rows[1] == Vector4(0, 1, 0, 0) &&
			m_rows[2] == Vector4(0, 0, 1, 0) && m_rows[3] == Vector4(0, 0, 0, 1);
}

// Is _mat matrix = identity matrix
bool Matrix4x4::IsIdentity(Matrix4x4 _mat)
{
	return _mat[0] == Vector4(1, 0, 0, 0) && _mat[1] == Vector4(0, 1, 0, 0) &&
			_mat[2] == Vector4(0, 0, 1, 0) && _mat[3] == Vector4(0, 0, 0, 1);
}

// Gets determinant of this matrix
float Matrix4x4::Determinant()
{
	return ((*this)[0][0] * FindSubMatrix4x4((*this), 0, 0).Determinant() - (*this)[1][0] * FindSubMatrix4x4((*this), 1, 0).Determinant() +
		(*this)[2][0] * FindSubMatrix4x4((*this), 2, 0).Determinant() - (*this)[3][0] * FindSubMatrix4x4((*this), 3, 0).Determinant());
}

// Gets determinant of _mat matrix
float Matrix4x4::Determinant(Matrix4x4 _mat)
{
	return (_mat[0][0] * FindSubMatrix4x4(_mat, 0, 0).Determinant() - _mat[1][0] * FindSubMatrix4x4(_mat, 1, 0).Determinant() +
		_mat[2][0] * FindSubMatrix4x4(_mat, 2, 0).Determinant() - _mat[3][0] * FindSubMatrix4x4(_mat, 3, 0).Determinant());
}

// Gets inverse of this matrix
Matrix4x4 Matrix4x4::Inverse()
{
	return (1.f / Determinant()) * FindCofactorMatrix4x4((*this)).Transpose();
}

// Gets inverse of _mat matrix
Matrix4x4 Matrix4x4::Inverse(Matrix4x4 _mat)
{
	return (1.f / Determinant(_mat)) * FindCofactorMatrix4x4(_mat).Transpose();
}

// Transposes this matrix
Matrix4x4 Matrix4x4::Transpose()
{
	return Matrix4x4
	(
		m_rows[0][0], m_rows[1][0], m_rows[2][0], m_rows[3][0],
		m_rows[0][1], m_rows[1][1], m_rows[2][1], m_rows[3][1],
		m_rows[0][2], m_rows[1][2], m_rows[2][2], m_rows[3][2],
		m_rows[0][3], m_rows[1][3], m_rows[2][3], m_rows[3][3]
	);
}

// Transposes _mat matrix
Matrix4x4 Matrix4x4::Transpose(Matrix4x4 _mat)
{
	return Matrix4x4
	(
		_mat[0][0], _mat[1][0], _mat[2][0], _mat[3][0],
		_mat[0][1], _mat[1][1], _mat[2][1], _mat[3][1],
		_mat[0][2], _mat[1][2], _mat[2][2], _mat[3][2],
		_mat[0][3], _mat[1][3], _mat[2][3], _mat[3][3]
	);
}
