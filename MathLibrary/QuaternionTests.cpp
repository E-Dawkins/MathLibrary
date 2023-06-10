#include "pch.h"
#include "CppUnitTest.h"
#include "Quaternion.h"
#include "Helpers.h"

using namespace HELPERS;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QUATERNIONS
{
	TEST_CLASS(QUATERNION)
	{
		TEST_METHOD(CONSTRUCTION)
		{
			Quaternion q = Quaternion();
			Assert::IsTrue(q.s == 0 && q.v == Vector3());

			q = Quaternion(1, Vector3(2, 3, 4));
			Assert::IsTrue(q.s == 1 && q.v == Vector3(2, 3, 4));

			q = Quaternion(Quaternion(1, Vector3(2, 3, 4)));
			Assert::IsTrue(q.s == 1 && q.v == Vector3(2, 3, 4));
		}

		TEST_METHOD(EQUALITY)
		{
			Assert::IsFalse(Quaternion(1, Vector3(2, 3, 4)) == Quaternion(4, Vector3(3, 2, 1)));
			Assert::IsTrue(Quaternion(1, Vector3(2, 3, 4)) != Quaternion(4, Vector3(3, 2, 1)));
		}

		TEST_METHOD(ADD_SUB)
		{
			Quaternion a(0.5, Vector3(2, 3, -4));
			Quaternion b(0.1, Vector3(4, 5, 6));
			Quaternion add = a + b;
			Quaternion sub = a - b;

			Assert::IsTrue(add.s = 0.6f && add.v == Vector3(6, 8, 2));
			Assert::IsTrue(sub.s = 0.4f && sub.v == Vector3(-2, -2, -10));

			a += b;
			b -= a;
			
			Assert::IsTrue(a.s == 0.6f && a.v == Vector3(6, 8, 2));
			Assert::IsTrue(b.s = -0.5f && b.v == Vector3(-2, -3, 4));
		}

		TEST_METHOD(MULTIPLY)
		{
			Quaternion a = Quaternion(3, Vector3(2, 4, 1));
			Quaternion b = Quaternion(1, Vector3(3, 5, 2));
			Quaternion result = Quaternion(-25, Vector3(14, 18, 5));

			Assert::IsTrue((a * b) == result);

			a *= b;
			Assert::IsTrue(a == result);

			Assert::IsTrue(a * 2 == Quaternion(-50, Vector3(28, 36, 10)));
			
			b *= 2;
			Assert::IsTrue(b == Quaternion(2, Vector3(6, 10, 4)));
		}

		TEST_METHOD(MAGNITUDE)
		{
			Quaternion q = Quaternion(1, Vector3(2, 3, 4));
			Assert::AreEqual(q.Magnitude(), sqrtf(30));
		}

		TEST_METHOD(NORMALIZE)
		{
			Quaternion q = Quaternion(0, Vector3(20, 10, 5));

			Assert::IsTrue(q.Normalized() == Quaternion(0, Vector3(0.8728716, 0.4364358, 0.2182179)));

			q.Normalize();
			Assert::IsTrue(q == Quaternion(0, Vector3(0.8728716, 0.4364358, 0.2182179)));
		}

		TEST_METHOD(CONJUGATE)
		{
			Quaternion q(1, Vector3(2, 3, 4));
			Assert::IsTrue(q.Conjugate() == Quaternion(1, Vector3(-2, -3, -4)));
		}

		TEST_METHOD(INVERSE)
		{
			Quaternion q(0, Vector3(20, 30, 25));
			Quaternion inv = q.Inverse();

			Assert::AreEqual(inv.s, 0.f);
			Assert::AreEqual(inv.v.x, -0.01038961f, (float)EPS);
			Assert::AreEqual(inv.v.y, -0.01558441f, (float)EPS);
			Assert::AreEqual(inv.v.z, -0.01298701f, (float)EPS);
		}

		TEST_METHOD(ROTATE_VECTOR)
		{
			Vector3 vec = Vector3(0, 1, 0);
			Vector3 axis = Vector3(1, 0, 0);

			Vector3 expected(0, 0, 1);
			Vector3 actual = Quaternion::RotateVector(vec, 90, axis);

			Assert::IsTrue(actual == expected);
		}

		TEST_METHOD(EULERS)
		{
			Vector3 eulers = Vector3(1.57079633, 0.4712389, 2.70526034);

			Quaternion q = Quaternion(eulers);
			Vector3 e = q.ToEuler();

			float diff = Vector3::Distance(eulers, e);
			Assert::IsTrue(diff <= 0.000001f);
		}

		TEST_METHOD(OSTREAM)
		{
			Quaternion q = Quaternion(1, Vector3(2, 3, 4));
			std::ostringstream os;
			os << q;
			Assert::AreEqual("(1, {2, 3, 4})", os.str().c_str());
		}
	};
}