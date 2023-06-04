#include "pch.h"
#include "CppUnitTest.h"
#include "Matrices.h"
#include "Vectors.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MATRICES
{
	TEST_CLASS(MATRIX2x2)
	{
		TEST_METHOD(CONSTRUCTION)
		{
			Matrix2x2 mat = Matrix2x2();
			Assert::IsTrue(mat.m1 == 0 && mat.m2 == 0 && mat.m3 == 0 && mat.m4 == 0);

			mat = Matrix2x2(1);
			Assert::IsTrue(mat.m1 == 1 && mat.m2 == 1 && mat.m3 == 1 && mat.m4 == 1);

			mat = Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(mat.m1 == 1 && mat.m2 == 2 && mat.m3 == 3 && mat.m4 == 4);
		}

		TEST_METHOD(ADDITION)
		{
			Matrix2x2 mat = Matrix2x2(2);

			mat = mat + Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(mat.m1 == 3 && mat.m2 == 4 && mat.m3 == 5 && mat.m4 == 6);

			mat = mat + 1;
			Assert::IsTrue(mat.m1 == 4 && mat.m2 == 5 && mat.m3 == 6 && mat.m4 == 7);

			mat += Matrix2x2(0.5f);
			Assert::IsTrue(mat.m1 == 4.5f && mat.m2 == 5.5f && mat.m3 == 6.5f && mat.m4 == 7.5f);

			mat += 1.5f;
			Assert::IsTrue(mat.m1 == 6 && mat.m2 == 7 && mat.m3 == 8 && mat.m4 == 9);
		}

		TEST_METHOD(SUBTRACTION)
		{
			Matrix2x2 mat = Matrix2x2(10);

			mat = mat - Matrix2x2(2);
			Assert::IsTrue(mat.m1 == 8 && mat.m2 == 8 && mat.m3 == 8 && mat.m4 == 8);

			mat = mat - 1;
			Assert::IsTrue(mat.m1 == 7 && mat.m2 == 7 && mat.m3 == 7 && mat.m4 == 7);

			mat -= Matrix2x2(3);
			Assert::IsTrue(mat.m1 == 4 && mat.m2 == 4 && mat.m3 == 4 && mat.m4 == 4);

			mat -= 4;
			Assert::IsTrue(mat.m1 == 0 && mat.m2 == 0 && mat.m3 == 0 && mat.m4 == 0);
		}

		TEST_METHOD(MULTIPLICATION)
		{
			Matrix2x2 mat = Matrix2x2(1, 2, 3, 4);

			mat = mat * 2.5f;
			Assert::IsTrue(mat.m1 == 2.5f && mat.m2 == 5 && mat.m3 == 7.5f && mat.m4 == 10);

			mat = mat * 3;
			Assert::IsTrue(mat.m1 == 7.5f && mat.m2 == 15 && mat.m3 == 22.5f && mat.m4 == 30);

			mat *= 4;
			Assert::IsTrue(mat.m1 == 30 && mat.m2 == 60 && mat.m3 == 90 && mat.m4 == 120);

			mat = Matrix2x2(2, 1, 5, 2) * Matrix2x2(1, 4, 3, 6);
			Assert::IsTrue(mat.m1 == 5 && mat.m2 == 14 && mat.m3 == 11 && mat.m4 == 32);

			Vector2 vec = Matrix2x2(1, 2, 3, 4) * Vector2(2, 1);
			Assert::IsTrue(vec.x == 4 && vec.y == 10);

			vec = Vector2(2, 1) * Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(vec.x == 4 && vec.y == 10);
		}

		TEST_METHOD(DIVISION)
		{
			Matrix2x2 mat = Matrix2x2(100);

			mat = mat / 2;
			Assert::IsTrue(mat.m1 == 50 && mat.m2 == 50 && mat.m3 == 50 && mat.m4 == 50);

			mat = mat / 5;
			Assert::IsTrue(mat.m1 == 10 && mat.m2 == 10 && mat.m3 == 10 && mat.m4 == 10);

			mat /= 5;
			Assert::IsTrue(mat.m1 == 2 && mat.m2 == 2 && mat.m3 == 2 && mat.m4 == 2);
		}

		TEST_METHOD(GLOBALS)
		{
			Matrix2x2 mat = Matrix2x2::zero;
			Assert::IsTrue(mat.m1 == 0 && mat.m2 == 0 && mat.m3 == 0 && mat.m4 == 0);

			mat = Matrix2x2::identity;
			Assert::IsTrue(mat.m1 == 1 && mat.m2 == 0 && mat.m3 == 0 && mat.m4 == 1);
		}
	};

	TEST_CLASS(MATRIX3x3)
	{

	};

	TEST_CLASS(MATRIX4x4)
	{

	};
}