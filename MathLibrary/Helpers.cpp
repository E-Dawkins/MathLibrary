#pragma once
#include "pch.h"
#include "Helpers.h"
#include "Matrices.h"
#include "Vectors.h"

float HELPERS::Deg2Rad(float _degrees)
{
	return _degrees * ((float)PI / 180.f);
}

float HELPERS::Rad2Deg(float _radians)
{
	return _radians * (180.f / (float)PI);
}

Matrix3x3 HELPERS::FindSubMatrix4x4(Matrix4x4 _mat, int _row, int _col)
{
	Matrix3x3 remainsMat;

	int curRow = 0;

	for (int i = 0; i < 4; i++)
	{
		if (i == _row)
			continue;

		int curCol = 0;

		for (int j = 0; j < 4; j++)
		{
			if (j == _col)
				continue;

			remainsMat[curRow][curCol] = _mat[i][j];
			curCol++;
		}

		curRow++;
	}

	return remainsMat;
}

float HELPERS::FindCofactor4x4(Matrix4x4 _mat, int _row, int _col)
{
	return powf(-1.f, (float)(_row + _col + 2)) * FindSubMatrix4x4(_mat, _row, _col).Determinant();
}

Matrix4x4 HELPERS::FindCofactorMatrix4x4(Matrix4x4 _mat)
{
	Matrix4x4 output = Matrix4x4();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			output(i, j) = FindCofactor4x4(_mat, i, j);
		}
	}

	return output;
}

Matrix2x2 HELPERS::FindSubMatrix3x3(Matrix3x3 _mat, int _row, int _col)
{
	Matrix2x2 remainsMat;

	int curRow = 0;

	for (int i = 0; i < 3; i++)
	{
		if (i == _row)
			continue;

		int curCol = 0;

		for (int j = 0; j < 3; j++)
		{
			if (j == _col)
				continue;

			remainsMat[curRow][curCol] = _mat[i][j];
			curCol++;
		}

		curRow++;
	}

	return remainsMat;
}

float HELPERS::FindCofactor3x3(Matrix3x3 _mat, int _row, int _col)
{
	return powf(-1.f, (float)(_row + _col + 2)) * FindSubMatrix3x3(_mat, _row, _col).Determinant();
}

Matrix3x3 HELPERS::FindCofactorMatrix3x3(Matrix3x3 _mat)
{
	Matrix3x3 output = Matrix3x3();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			output(i, j) = FindCofactor3x3(_mat, i, j);
		}
	}

	return output;
}

float HELPERS::Clamp(float _value, float _min, float _max)
{
	return (_value < _min ? _min : (_value > _max ? _max : _value));
}

double HELPERS::Clamp(double _value, double _min, double _max)
{
	return (_value < _min ? _min : (_value > _max ? _max : _value));
}

int HELPERS::Clamp(int _value, int _min, int _max)
{
	return (_value < _min ? _min : (_value > _max ? _max : _value));
}
