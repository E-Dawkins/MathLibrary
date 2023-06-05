#pragma once
#include "defs.h"
#include <vector>
#include <iostream>
#include "Vector3.h"

class MATHLIBRARY_API Matrix3x3
{
public:
	Matrix3x3();
	Matrix3x3(float _value);
	Matrix3x3(float _m1, float _m2, float _m3, float _m4, 
		float _m5, float _m6, float _m7, float _m8, float _m9);

	static Matrix3x3 zero;
	static Matrix3x3 identity;

	Matrix3x3 operator + (Matrix3x3 _other);
	Matrix3x3 operator + (float _value);
	void operator += (Matrix3x3 _other);
	void operator += (float _value);

	Matrix3x3 operator - (Matrix3x3 _other);
	Matrix3x3 operator - (float _value);
	void operator -= (Matrix3x3 _other);
	void operator -= (float _value);

	friend Matrix3x3 operator * (float _multi, Matrix3x3 _mat);
	friend Matrix3x3 operator * (Matrix3x3 _mat, float _multi);
	void operator *= (float _multi);
	friend Matrix3x3 operator * (Matrix3x3 _a, Matrix3x3 _b);
	friend Vector3 operator * (Matrix3x3 _mat, Vector3 _vec);
	friend Vector3 operator * (Vector3 _vec, Matrix3x3 _mat);

	friend Matrix3x3 operator / (Matrix3x3 _mat, float _div);
	void operator /= (float _div);

	Vector3& operator [] (int _row);
	float& operator () (int _row, int _index);

	bool operator == (Matrix3x3 _other);
	bool operator != (Matrix3x3 _other);

	friend void operator << (std::ostream& _os, Matrix3x3& _mat);

	Vector3& GetRow(int _row);
	Vector3 GetCol(int _col);

	bool IsIdentity();
	static bool IsIdentity(Matrix3x3 _mat);

	float Determinant();
	static float Determinant(Matrix3x3 _mat);

	Matrix3x3 Inverse();
	static Matrix3x3 Inverse(Matrix3x3 _mat);

	Matrix3x3 Transpose();
	static Matrix3x3 Transpose(Matrix3x3 _mat);

protected:
	std::vector<Vector3> m_rows;

	float FindCofactor(int _row, int _col);
};