#include "pch.h"
#include "CppUnitTest.h"
#include "Matrices.h"
#include "Vectors.h"
#include "defs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MATRICES
{
	TEST_CLASS(MATRIX2x2)
	{
		TEST_METHOD(CONSTRUCTION)
		{
			Matrix2x2 mat = Matrix2x2();
			Assert::IsTrue(mat[0] == Vector2(0) && mat[1] == Vector2(0));

			mat = Matrix2x2(1);
			Assert::IsTrue(mat[0] == Vector2(1) && mat[1] == Vector2(1));

			mat = Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(mat[0] == Vector2(1, 2) && mat[1] == Vector2(3, 4));
		}

		TEST_METHOD(EQUALITY)
		{
			Assert::IsFalse(Matrix2x2(1, 2, 3, 4) == Matrix2x2(4, 3, 2, 1));
			Assert::IsTrue(Matrix2x2(1, 2, 3, 4) != Matrix2x2(4, 3, 2, 1));
			
			Matrix2x2 mat = Matrix2x2(1, 0, 0, 1);
			Assert::IsTrue(mat.IsIdentity() && Matrix2x2::IsIdentity(mat));
		}

		TEST_METHOD(ADDITION)
		{
			Matrix2x2 mat = Matrix2x2(2);

			mat = mat + Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(mat == Matrix2x2(3, 4, 5, 6));

			mat = mat + 1;
			Assert::IsTrue(mat == Matrix2x2(4, 5, 6, 7));

			mat += Matrix2x2(0.5f);
			Assert::IsTrue(mat == Matrix2x2(4.5f, 5.5f, 6.5f, 7.5f));

			mat += 1.5f;
			Assert::IsTrue(mat == Matrix2x2(6, 7, 8, 9));
		}

		TEST_METHOD(SUBTRACTION)
		{
			Matrix2x2 mat = Matrix2x2(10);

			mat = mat - Matrix2x2(2);
			Assert::IsTrue(mat == Matrix2x2(8));

			mat = mat - 1;
			Assert::IsTrue(mat == Matrix2x2(7));

			mat -= Matrix2x2(3);
			Assert::IsTrue(mat == Matrix2x2(4));

			mat -= 4;
			Assert::IsTrue(mat == Matrix2x2(0));
		}

		TEST_METHOD(MULTIPLICATION)
		{
			Matrix2x2 mat = Matrix2x2(1, 2, 3, 4);

			mat = mat * 2.5f;
			Assert::IsTrue(mat == Matrix2x2(2.5f, 5, 7.5f, 10));

			mat = mat * 3;
			Assert::IsTrue(mat == Matrix2x2(7.5f, 15, 22.5f, 30));

			mat *= 4;
			Assert::IsTrue(mat == Matrix2x2(30, 60, 90, 120));

			mat = Matrix2x2(2, 1, 5, 2) * Matrix2x2(1, 4, 3, 6);
			Assert::IsTrue(mat == Matrix2x2(5, 14, 11, 32));

			Vector2 vec = Matrix2x2(1, 2, 3, 4) * Vector2(2, 1);
			Assert::IsTrue(vec == Vector2(4, 10));

			vec = Vector2(2, 1) * Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(vec == Vector2(5, 8));
		}

		TEST_METHOD(DIVISION)
		{
			Matrix2x2 mat = Matrix2x2(100);

			mat = mat / 2;
			Assert::IsTrue(mat == Matrix2x2(50));

			mat = mat / 5;
			Assert::IsTrue(mat == Matrix2x2(10));

			mat /= 5;
			Assert::IsTrue(mat == Matrix2x2(2));
		}

		TEST_METHOD(GLOBALS)
		{
			Matrix2x2 mat = Matrix2x2::zero;
			Assert::IsTrue(mat == Matrix2x2(0));

			mat = Matrix2x2::identity;
			Assert::IsTrue(mat == Matrix2x2(1, 0, 0, 1));
		}

		TEST_METHOD(SUBSCRIPTS)
		{
			Matrix2x2 mat = Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(mat[1] == Vector2(3, 4));
			Assert::IsTrue(mat(0, 1) == 2);
			Assert::IsTrue(mat.GetRow(0) == Vector2(1, 2));
			Assert::IsTrue(mat.GetCol(1) == Vector2(2, 4));
		}

		TEST_METHOD(OSTREAM)
		{
			Matrix2x2 mat = Matrix2x2(1, 2, 3, 4);
			std::ostringstream os;
			os << mat;
			Assert::AreEqual("(1, 2, 3, 4)", os.str().c_str());
		}

		TEST_METHOD(FUNCTIONS)
		{
			Matrix2x2 mat = Matrix2x2(1, 2, 3, 4);
			Assert::IsTrue(mat.Determinant() == -2);
			Assert::IsTrue(Matrix2x2::Determinant(mat) == -2);

			mat = Matrix2x2(4, 7, 2, 6);
			Assert::IsTrue(mat.Inverse() == Matrix2x2(0.6f, -0.7f, -0.2f, 0.4f));
			Assert::IsTrue(Matrix2x2::Inverse(mat) == Matrix2x2(0.6f, -0.7f, -0.2f, 0.4f));

			Assert::IsTrue(mat.Transpose() == Matrix2x2(4, 2, 7, 6));
			Assert::IsTrue(Matrix2x2::Transpose(mat) == Matrix2x2(4, 2, 7, 6));
		}
	};

	TEST_CLASS(MATRIX3x3)
	{
		TEST_METHOD(CONSTRUCTION)
		{
			Matrix3x3 mat = Matrix3x3();
			Assert::IsTrue(mat[0] == Vector3(0) && mat[1] == Vector3(0) && mat[2] == Vector3(0));

			mat = Matrix3x3(1);
			Assert::IsTrue(mat[0] == Vector3(1) && mat[1] == Vector3(1) && mat[2] == Vector3(1));

			mat = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
			Assert::IsTrue(mat[0] == Vector3(1, 2, 3) && mat[1] == Vector3(4, 5, 6) && mat[2] == Vector3(7, 8, 9));
		}

		TEST_METHOD(EQUALITY)
		{
			Assert::IsFalse(Matrix3x3(1) == Matrix3x3(2));
			Assert::IsTrue(Matrix3x3(1) != Matrix3x3(2));

			Matrix3x3 mat = Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1);
			Assert::IsTrue(mat.IsIdentity() && Matrix3x3::IsIdentity(mat));
		}

		TEST_METHOD(ADDITION)
		{
			Matrix3x3 mat = Matrix3x3(2);

			mat = mat + Matrix3x3(1);
			Assert::IsTrue(mat == Matrix3x3(3));

			mat = mat + 1;
			Assert::IsTrue(mat == Matrix3x3(4));

			mat += Matrix3x3(0.5f);
			Assert::IsTrue(mat == Matrix3x3(4.5f));

			mat += 1.5f;
			Assert::IsTrue(mat == Matrix3x3(6));
		}

		TEST_METHOD(SUBTRACTION)
		{
			Matrix3x3 mat = Matrix3x3(10);

			mat = mat - Matrix3x3(2);
			Assert::IsTrue(mat == Matrix3x3(8));

			mat = mat - 1;
			Assert::IsTrue(mat == Matrix3x3(7));

			mat -= Matrix3x3(3);
			Assert::IsTrue(mat == Matrix3x3(4));

			mat -= 4;
			Assert::IsTrue(mat == Matrix3x3(0));
		}

		TEST_METHOD(MULTIPLICATION)
		{
			Matrix3x3 mat = Matrix3x3(4);

			mat = mat * 2.5f;
			Assert::IsTrue(mat == Matrix3x3(10));

			mat = mat * 3;
			Assert::IsTrue(mat == Matrix3x3(30));

			mat *= 4;
			Assert::IsTrue(mat == Matrix3x3(120));

			mat = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9) * Matrix3x3(9, 8, 7, 6, 5, 4, 3, 2, 1);
			Assert::IsTrue(mat == Matrix3x3(30, 24, 18, 84, 69, 54, 138, 114, 90));

			Vector3 vec = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9) * Vector3(3, 2, 1);
			Assert::IsTrue(vec == Vector3(10, 28, 46));

			vec = Vector3(3, 2, 1) * Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
			Assert::IsTrue(vec == Vector3(18, 24, 30));
		}

		TEST_METHOD(DIVISION)
		{
			Matrix3x3 mat = Matrix3x3(100);

			mat = mat / 2;
			Assert::IsTrue(mat == Matrix3x3(50));

			mat = mat / 5;
			Assert::IsTrue(mat == Matrix3x3(10));

			mat /= 5;
			Assert::IsTrue(mat == Matrix3x3(2));
		}

		TEST_METHOD(GLOBALS)
		{
			Matrix3x3 mat = Matrix3x3::zero;
			Assert::IsTrue(mat == Matrix3x3(0));

			mat = Matrix3x3::identity;
			Assert::IsTrue(mat == Matrix3x3(1, 0, 0, 0, 1, 0, 0, 0, 1));
		}

		TEST_METHOD(SUBSCRIPTS)
		{
			Matrix3x3 mat = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
			Assert::IsTrue(mat[1] == Vector3(4, 5, 6));
			Assert::IsTrue(mat(0, 1) == 2);
			Assert::IsTrue(mat.GetRow(0) == Vector3(1, 2, 3));
			Assert::IsTrue(mat.GetCol(1) == Vector3(2, 5, 8));
		}

		TEST_METHOD(OSTREAM)
		{
			Matrix3x3 mat = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
			std::ostringstream os;
			os << mat;
			Assert::AreEqual("(1, 2, 3, 4, 5, 6, 7, 8, 9)", os.str().c_str());
		}

		TEST_METHOD(FUNCTIONS)
		{
			Matrix3x3 mat = Matrix3x3::identity * 2;
			Assert::AreEqual(8.f, mat.Determinant());
			Assert::AreEqual(8.f, Matrix3x3::Determinant(mat));

			mat = Matrix3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);
			Assert::IsTrue(mat.Transpose() == Matrix3x3(1, 4, 7, 2, 5, 8, 3, 6, 9));
			Assert::IsTrue(Matrix3x3::Transpose(mat) == Matrix3x3(1, 4, 7, 2, 5, 8, 3, 6, 9));

			mat = Matrix3x3(4, 5, 4, 3, 4, 5, 2, 3, 2);
			Assert::IsTrue(mat.Inverse() == Matrix3x3(1.75f, -0.5f, -2.25f, -1, 0, 2, -0.25f, 0.5f, -0.25f));
			Assert::IsTrue(Matrix3x3::Inverse(mat) == Matrix3x3(1.75f, -0.5f, -2.25f, -1, 0, 2, -0.25f, 0.5f, -0.25f));
		}
	};

	TEST_CLASS(MATRIX4x4)
	{

	};
}