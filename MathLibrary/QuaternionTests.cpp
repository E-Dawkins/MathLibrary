#include "pch.h"
#include "CppUnitTest.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Matrix4x4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QUATERNIONS
{
	TEST_CLASS(QUATERNION)
	{
		TEST_METHOD(CONSTRUCTION)
		{
			Quaternion quat = Quaternion();
			Assert::IsTrue(quat.x == 0 && quat.y == 0 && quat.z == 0 && quat.w == 1);

			quat = Quaternion(1, 2, 3, 4);
			Assert::IsTrue(quat.x == 1 && quat.y == 2 && quat.z == 3 && quat.w == 4);
		}

		TEST_METHOD(EQUALITY)
		{
			Quaternion quat = Quaternion(1, 2, 3, 4);
			Assert::IsFalse(quat == Quaternion(4, 3, 2, 1));
			Assert::IsTrue(quat != Quaternion(4, 3, 2, 1));

			quat = Quaternion(0, 0, 0, 1);
			Assert::IsTrue(quat.IsIdentity());
			Assert::IsTrue(Quaternion::IsIdentity(quat));
		}

		TEST_METHOD(SUBSCRIPT)
		{
			Quaternion quat = Quaternion(1, 2, 3, 4);
			Assert::AreEqual(2.f, quat[1]);
		}

		TEST_METHOD(OSTREAM)
		{
			Quaternion quat = Quaternion(1, 2, 3, 4);
			std::ostringstream os;
			os << quat;
			Assert::AreEqual("(1, 2, 3, 4)", os.str().c_str());
		}

		TEST_METHOD(GLOBALS)
		{
			Quaternion quat = Quaternion::identity;
			Assert::IsTrue(quat == Quaternion(0, 0, 0, 1));

			quat = Quaternion(1, 2, 3);
			Assert::IsTrue(quat.Vector() == Vector3(1, 2, 3));
		}

		TEST_METHOD(MULTIPLICATION)
		{
			Quaternion quatA = Quaternion(1, 2, 3, 10);
			Quaternion quatB = Quaternion(3, 2, 1, 5);
			Assert::IsTrue((quatA * quatB) == Quaternion(31, 38, 21, 40));
			Assert::IsTrue((quatA * -1.f) == Quaternion(-1, -2, -3, -10));
			Assert::IsTrue((-1.f * quatA) == Quaternion(-1, -2, -3, -10));
		}

		TEST_METHOD(ADDITION)
		{
			Quaternion quatA = Quaternion(1, 2, 3, 10);
			Quaternion quatB = Quaternion(3, 2, 1, 5);
			Assert::IsTrue((quatA + quatB) == Quaternion(4, 4, 4, 15));
		}

		TEST_METHOD(SUBTRACTION)
		{
			Quaternion quatA = Quaternion(1, 2, 3, 10);
			Quaternion quatB = Quaternion(3, 2, 1, 5);
			Assert::IsTrue((quatA - quatB) == Quaternion(-2, 0, 2, 5));
		}

		TEST_METHOD(MAGNITUDE)
		{
			Quaternion quat = Quaternion(3, 2, 1, 10);
			Assert::AreEqual(sqrtf(114), quat.Magnitude());
			Assert::AreEqual(sqrtf(114), Quaternion::Magnitude(quat));
		}

		TEST_METHOD(CONJUGATE)
		{
			Quaternion quat = Quaternion(-1, 1, 3, 2);
			Assert::IsTrue(quat.Conjugate() == Quaternion(1, -1, -3, 2));
			Assert::IsTrue(Quaternion::Conjugate(quat) == Quaternion(1, -1, -3, 2));
		}

		TEST_METHOD(DOT)
		{
			Quaternion quat = Quaternion(0, 1, 0);
			Assert::AreEqual(0.f, quat.Dot(Quaternion(1, 0, 0)));
			Assert::AreEqual(0.f, Quaternion::Dot(quat, Quaternion(1, 0, 0)));
		}

		TEST_METHOD(INTERPOLATION)
		{
			Quaternion lerped = Quaternion::Lerp(Quaternion(0, 1, 0), Quaternion(0, -1, 0), 0.5f);
			Quaternion slerped = Quaternion::Slerp(Quaternion(0, 1, 0), Quaternion(-1, 0, 0), 0.5f);

			Assert::IsTrue(lerped == Quaternion(0, 0, 0));
			Assert::IsTrue(slerped == Quaternion(-0.7071067811865475f, 0.7071067811865475f, 0));
		}
	};
}