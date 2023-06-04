#pragma once
class Vector2;

class Matrix2x2
{
public:
	Matrix2x2();
	Matrix2x2(float _value);
	Matrix2x2(float _m1, float _m2, float _m3, float _m4);

	float m1 = 0;
	float m2 = 0;
	float m3 = 0;
	float m4 = 0;

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

	friend Matrix2x2 operator / (float _div, Matrix2x2 _mat);
	friend Matrix2x2 operator / (Matrix2x2 _mat, float _div);
	void operator /= (float _div);

	Matrix2x2 Inverse();
	static Matrix2x2 Inverse(Matrix2x2 _mat);
};