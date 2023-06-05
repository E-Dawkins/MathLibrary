#pragma once
#include "defs.h"
#include <vector>
#include <iostream>
#include "Vector2.h"

class MATHLIBRARY_API Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(float _value);
	Matrix2x2(float _m1, float _m2, float _m3, float _m4);

	static Matrix2x2 zero;
	static Matrix2x2 identity;

	Matrix2x2 operator + (Matrix2x2 _other);
	Matrix2x2 operator + (float _value);
	void operator += (Matrix2x2 _other);
	void operator += (float _value);

	Matrix2x2 operator - (Matrix2x2 _other);
	Matrix2x2 operator - (float _value);
	void operator -= (Matrix2x2 _other);
	void operator -= (float _value);

	friend Matrix2x2 operator * (float _multi, Matrix2x2 _mat);
	friend Matrix2x2 operator * (Matrix2x2 _mat, float _multi);
	void operator *= (float _multi);
	friend Matrix2x2 operator * (Matrix2x2 _a, Matrix2x2 _b);
	friend Vector2 operator * (Matrix2x2 _mat, Vector2 _vec);
	friend Vector2 operator * (Vector2 _vec, Matrix2x2 _mat);

	friend Matrix2x2 operator / (Matrix2x2 _mat, float _div);
	void operator /= (float _div);

	Vector2& operator [] (int _row);
	float& operator () (int _row, int _col);

	bool operator == (Matrix2x2 _other);
	bool operator != (Matrix2x2 _other);

	friend void operator << (std::ostream& _os, Matrix2x2& _mat);

	Vector2& GetRow(int _row);
	Vector2 GetCol(int _col);

	bool IsIdentity();
	static bool IsIdentity(Matrix2x2 _mat);

	float Determinant();
	static float Determinant(Matrix2x2 _mat);

	Matrix2x2 Inverse();
	static Matrix2x2 Inverse(Matrix2x2 _mat);

	Matrix2x2 Transpose();
	static Matrix2x2 Transpose(Matrix2x2 _mat);

protected:
	std::vector<Vector2> m_rows;
};