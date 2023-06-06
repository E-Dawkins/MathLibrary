#pragma once
#include "defs.h"
#include "Vector4.h"
#include <vector>
#include <iostream>

class MATHLIBRARY_API Matrix4x4
{
public:
	Matrix4x4();
	Matrix4x4(float _value);
	Matrix4x4(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8,
		float _m9, float _m10, float _m11, float _m12, float _m13, float _m14, float _m15, float _m16);

	static Matrix4x4 zero;
	static Matrix4x4 identity;

	Matrix4x4 operator + (Matrix4x4 _other);
	Matrix4x4 operator + (float _value);
	void operator += (Matrix4x4 _other);
	void operator += (float _value);

	Matrix4x4 operator - (Matrix4x4 _other);
	Matrix4x4 operator - (float _value);
	void operator -= (Matrix4x4 _other);
	void operator -= (float _value);

	friend Matrix4x4 operator * (float _multi, Matrix4x4 _mat);
	friend Matrix4x4 operator * (Matrix4x4 _mat, float _multi);
	void operator *= (float _multi);
	friend Matrix4x4 operator * (Matrix4x4 _a, Matrix4x4 _b);
	friend Vector4 operator * (Matrix4x4 _mat, Vector4 _vec);
	friend Vector4 operator * (Vector4 _vec, Matrix4x4 _mat);

	friend Matrix4x4 operator / (Matrix4x4 _mat, float _div);
	void operator /= (float _div);

	Vector4& operator [] (int _index);
	float& operator () (int _row, int _col);

	bool operator == (Matrix4x4 _other);
	bool operator != (Matrix4x4 _other);

	friend void operator << (std::ostream& _os, Matrix4x4& _mat);

	Vector4& GetRow(int _row);
	Vector4 GetCol(int _col);

	bool IsIdentity();
	static bool IsIdentity(Matrix4x4 _mat);

	float Determinant();
	static float Determinant(Matrix4x4 _mat);

	Matrix4x4 Inverse();
	static Matrix4x4 Inverse(Matrix4x4 _mat);

	Matrix4x4 Transpose();
	static Matrix4x4 Transpose(Matrix4x4 _mat);

protected:
	std::vector<Vector4> m_rows;

};