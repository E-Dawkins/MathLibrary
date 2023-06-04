#include "pch.h"
#include "CppUnitTest.h"
#include "Vectors.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VECTORS
{
    TEST_CLASS(VECTOR2)
    {
    public:
        TEST_METHOD(CONSTRUCTION)
        {
            Vector2 tempVec = Vector2();
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0);

            tempVec = Vector2(3);
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 3);

            tempVec = Vector2(1, 2);
            Assert::IsTrue(tempVec.x == 1 && tempVec.y == 2);
        }

        TEST_METHOD(ADDITION)
        {
            Vector2 tempVec = Vector2(1, 2);

            tempVec = tempVec + Vector2(2, 1);
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 3);

            tempVec = tempVec + 3;
            Assert::IsTrue(tempVec.x == 6 && tempVec.y == 6);

            tempVec += Vector2(2, 1);
            Assert::IsTrue(tempVec.x == 8 && tempVec.y == 7);

            tempVec += 2;
            Assert::IsTrue(tempVec.x == 10 && tempVec.y == 9);
        }

        TEST_METHOD(SUBTRACTION)
        {
            Vector2 tempVec = Vector2(10, 9);

            tempVec = tempVec - Vector2(10, 9);
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0);

            tempVec = tempVec - 3;
            Assert::IsTrue(tempVec.x == -3 && tempVec.y == -3);

            tempVec -= Vector2(2, 1);
            Assert::IsTrue(tempVec.x == -5 && tempVec.y == -4);

            tempVec -= 2;
            Assert::IsTrue(tempVec.x == -7 && tempVec.y == -6);
        }

        TEST_METHOD(MULTIPLICATION)
        {
            Vector2 tempVec = Vector2(-7, -6);

            tempVec = tempVec * -1;
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 6);

            tempVec *= 1.5f;
            Assert::IsTrue(tempVec.x == 10.5f && tempVec.y == 9);
        }

        TEST_METHOD(DIVISION)
        {
            Vector2 tempVec = Vector2(10.5f, 9);

            tempVec = tempVec / 1.5f;
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 6);

            tempVec /= 2;
            Assert::IsTrue(tempVec.x == 3.5f && tempVec.y == 3);
        }

        TEST_METHOD(OSTREAM)
        {
            Vector2 tempVec = Vector2(2.345f);
            std::ostringstream out;
            out << tempVec;
            Assert::AreEqual("(2.345, 2.345)", out.str().c_str());
        }

        TEST_METHOD(EQUALITY)
        {
            Vector2 tempVec = Vector2(1, 2);
            Assert::IsFalse(tempVec == Vector2(3, 2));
            Assert::IsTrue(tempVec != Vector2(3, 2));
        }

        TEST_METHOD(SUBSCRIPT)
        {
            Vector2 tempVec = Vector2(1.343f, 9.999f);
            Assert::IsTrue(tempVec[0] == 1.343f && tempVec[1] == 9.999f);

            tempVec[0] = 0.15f;
            tempVec[1] = 1.2f;
            Assert::IsTrue(tempVec[0] == 0.15f && tempVec[1] == 1.2f);

            tempVec[0] = tempVec[1];
            Assert::AreEqual(tempVec[0], 1.2f);
        }

        TEST_METHOD(GLOBALS)
        {
            Vector2 vecZero = Vector2::zero;
            Vector2 vecOne = Vector2::one;
            Vector2 vecHalf = Vector2::half;

            Assert::IsTrue(vecZero.x == 0 && vecZero.y == 0);
            Assert::IsTrue(vecOne.x == 1 && vecOne.y == 1);
            Assert::IsTrue(vecHalf.x == 0.5f && vecHalf.y == 0.5f);
        }

        TEST_METHOD(FUNCTIONS)
        {
            Vector2 temp = Vector2(2, 7);
            Assert::AreEqual(temp.Magnitude(), sqrtf(53));

            temp = Vector2(10, 0);
            Assert::IsTrue(temp.Normalized() == Vector2(1, 0));

            temp = Vector2(2, 2).Normalized();
            Assert::AreEqual(45.f, temp.Angle(Vector2(0, 1)), 0.0001f);

            temp = Vector2(2, 4);
            Assert::AreEqual(temp.Cross(Vector2(3, 5)), 26.f);

            Vector2 lerp = Vector2::Lerp(temp, Vector2(4, 8), 0.25f);
            Assert::IsTrue(lerp.x == 2.5f && lerp.y == 5);

            float dist = Vector2::Distance(temp, Vector2(3, 5));
            Assert::AreEqual(dist, sqrtf(2));

            Vector2 reflected = Vector2::Reflect(temp, Vector2(0, -1));
            Assert::IsTrue(reflected.x == 2 && reflected.y == -4);
        }
    };

    TEST_CLASS(VECTOR3)
    {
        TEST_METHOD(CONSTRUCTION)
        {
            Vector3 tempVec = Vector3();
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0 && tempVec.z == 0);

            tempVec = Vector3(2);
            Assert::IsTrue(tempVec.x == 2 && tempVec.y == 2 && tempVec.z == 2);

            tempVec = Vector3(1, 2, 3);
            Assert::IsTrue(tempVec.x == 1 && tempVec.y == 2 && tempVec.z == 3);
        }

        TEST_METHOD(ADDITION)
        {
            Vector3 tempVec = Vector3(2);

            tempVec = tempVec + Vector3(1, 2, 3);
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 4 && tempVec.z == 5);

            tempVec = tempVec + 1;
            Assert::IsTrue(tempVec.x == 4 && tempVec.y == 5 && tempVec.z == 6);

            tempVec += 2;
            Assert::IsTrue(tempVec.x == 6 && tempVec.y == 7 && tempVec.z == 8);

            tempVec += Vector3(1, 0, -1);
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 7 && tempVec.z == 7);
        }

        TEST_METHOD(SUBTRACTION)
        {
            Vector3 tempVec = Vector3(7);

            tempVec = tempVec - Vector3(7);
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0 && tempVec.z == 0);

            tempVec = tempVec - 1;
            Assert::IsTrue(tempVec.x == -1 && tempVec.y == -1 && tempVec.z == -1);

            tempVec -= 2;
            Assert::IsTrue(tempVec.x == -3 && tempVec.y == -3 && tempVec.z == -3);

            tempVec -= Vector3(-3, 2, -5);
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -5 && tempVec.z == 2);
        }

        TEST_METHOD(MULTIPLICATION)
        {
            Vector3 tempVec = Vector3(0, -5, 2);

            tempVec = tempVec * 2.5f;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -12.5f && tempVec.z == 5);

            tempVec *= 2;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -25 && tempVec.z == 10);
        }

        TEST_METHOD(DIVISION)
        {
            Vector3 tempVec = Vector3(0, -25, 10);

            tempVec = tempVec / 2;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -12.5f && tempVec.z == 5);

            tempVec /= 2.5f;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -5 && tempVec.z == 2);
        }

        TEST_METHOD(OSTREAM)
        {
            Vector3 tempVec = Vector3(1, 2, 3);
            std::ostringstream out;
            out << tempVec;
            Assert::AreEqual("(1, 2, 3)", out.str().c_str());
        }

        TEST_METHOD(EQUALITY)
        {
            Vector3 tempVec = Vector3(1, 2, 3);
            Assert::IsFalse(tempVec == Vector3(3, 2, 1));
            Assert::IsTrue(tempVec != Vector3(3, 2, 1));
        }

        TEST_METHOD(SUBSCRIPT)
        {
            Vector3 tempVec = Vector3(0.11f, 0.22f, 0.33f);
            Assert::IsTrue(tempVec[0] == 0.11f && tempVec[1] == 0.22f && tempVec[2] == 0.33f);

            tempVec[0] = 1.2f;
            tempVec[1] = 2.2f;
            tempVec[2] = 3.2f;
            Assert::IsTrue(tempVec[0] == 1.2f && tempVec[1] == 2.2f && tempVec[2] == 3.2f);

            tempVec[0] = tempVec[1];
            tempVec[1] = tempVec[2];
            Assert::IsTrue(tempVec[0] == 2.2f && tempVec[1] == 3.2f && tempVec[2] == 3.2f);
        }

        TEST_METHOD(GLOBALS)
        {
            Vector3 vecZero = Vector3::zero;
            Vector3 vecOne = Vector3::one;
            Vector3 vecHalf = Vector3::half;

            Assert::IsTrue(vecZero.x == 0 && vecZero.y == 0 && vecZero.z == 0);
            Assert::IsTrue(vecOne.x == 1 && vecOne.y == 1 && vecOne.z == 1);
            Assert::IsTrue(vecHalf.x == 0.5f && vecHalf.y == 0.5f && vecHalf.z == 0.5f);
        }

        TEST_METHOD(FUNCTIONS)
        {
            Vector3 temp = Vector3(2, 7, 1);
            Assert::AreEqual(temp.Magnitude(), sqrtf(54));

            temp = Vector3(10, 0, 0);
            Assert::IsTrue(temp.Normalized() == Vector3(1, 0, 0));

            temp = Vector3(2).Normalized();
            Assert::AreEqual(54.74f, temp.Angle(Vector3(0, 1, 0)), 0.01f);

            temp = Vector3(2, 4, 3);
            Assert::AreEqual(temp.Cross(Vector3(3, 5, 0)), 26.f);

            Vector3 lerp = Vector3::Lerp(temp, Vector3(4, 8, 6), 0.25f);
            Assert::IsTrue(lerp.x == 2.5f && lerp.y == 5 && lerp.z == 3.75f);

            float dist = Vector3::Distance(temp, Vector3(3, 5, 4));
            Assert::AreEqual(dist, sqrtf(3));

            Vector3 reflected = Vector3::Reflect(temp, Vector3(0, -1, 0));
            Assert::IsTrue(reflected.x == 2 && reflected.y == -4 && reflected.z == 3);
        }
    };

    TEST_CLASS(VECTOR4)
    {
        TEST_METHOD(CONSTRUCTION)
        {
            Vector4 tempVec = Vector4();
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0 && tempVec.z == 0 && tempVec.w == 0);

            tempVec = Vector4(2);
            Assert::IsTrue(tempVec.x == 2 && tempVec.y == 2 && tempVec.z == 2 && tempVec.w == 2);

            tempVec = Vector4(1, 2, 3, 4);
            Assert::IsTrue(tempVec.x == 1 && tempVec.y == 2 && tempVec.z == 3 && tempVec.w == 4);
        }

        TEST_METHOD(ADDITION)
        {
            Vector4 tempVec = Vector4(2);
            
            tempVec = tempVec + Vector4(1);
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 3 && tempVec.z == 3 && tempVec.w == 3);

            tempVec = tempVec + 2;
            Assert::IsTrue(tempVec.x == 5 && tempVec.y == 5 && tempVec.z == 5 && tempVec.w == 5);

            tempVec += Vector4(1, 2, 3, 1);
            Assert::IsTrue(tempVec.x == 6 && tempVec.y == 7 && tempVec.z == 8 && tempVec.w == 6);

            tempVec += 1;
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 8 && tempVec.z == 9 && tempVec.w == 7);
        }

        TEST_METHOD(SUBTRACTION)
        {
            Vector4 tempVec = Vector4(10);

            tempVec = tempVec - Vector4(2);
            Assert::IsTrue(tempVec.x == 8 && tempVec.y == 8 && tempVec.z == 8 && tempVec.w == 8);

            tempVec = tempVec - 3;
            Assert::IsTrue(tempVec.x == 5 && tempVec.y == 5 && tempVec.z == 5 && tempVec.w == 5);

            tempVec -= Vector4(1, 2, 3, 1);
            Assert::IsTrue(tempVec.x == 4 && tempVec.y == 3 && tempVec.z == 2 && tempVec.w == 4);

            tempVec -= 1;
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 2 && tempVec.z == 1 && tempVec.w == 3);
        }

        TEST_METHOD(MULTIPLICATION)
        {
            Vector4 tempVec = Vector4(1.5f, 2, 0.5f, 1);
            
            tempVec = tempVec * 2;
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 4 && tempVec.z == 1 && tempVec.w == 2);

            tempVec *= 3;
            Assert::IsTrue(tempVec.x == 9 && tempVec.y == 12 && tempVec.z == 3 && tempVec.w == 6);
        }

        TEST_METHOD(DIVISION)
        {
            Vector4 tempVec = Vector4(12, 6.75f, 10.5f, 15);

            tempVec = tempVec / 1.5f;
            Assert::IsTrue(tempVec.x == 8 && tempVec.y == 4.5 && tempVec.z == 7 && tempVec.w == 10);

            tempVec /= 2;
            Assert::IsTrue(tempVec.x == 4 && tempVec.y == 2.25f && tempVec.z == 3.5f && tempVec.w == 5);
        }

        TEST_METHOD(OSTREAM)
        {
            Vector4 tempVec = Vector4(1, 2, 3, 4);
            std::ostringstream os;
            os << tempVec;
            Assert::AreEqual("(1, 2, 3, 4)", os.str().c_str());
        }

        TEST_METHOD(EQUALITY)
        {
            Vector4 tempVec = Vector4(1, 2, 3, 4);
            Assert::IsFalse(tempVec == Vector4(4, 3, 2, 1));
            Assert::IsTrue(tempVec != Vector4(4, 3, 2, 1));
        }

        TEST_METHOD(SUBSCRIPT)
        {
            Vector4 tempVec = Vector4(1, 2, 3, 4);
            Assert::IsTrue(tempVec[0] == 1 && tempVec[1] == 2 && tempVec[2] == 3 && tempVec[3] == 4);

            tempVec[0] = 4;
            tempVec[1] = 3;
            tempVec[2] = 2;
            tempVec[3] = 1;
            Assert::IsTrue(tempVec[0] == 4 && tempVec[1] == 3 && tempVec[2] == 2 && tempVec[3] == 1);

            tempVec[0] = tempVec[1];
            tempVec[1] = tempVec[2];
            tempVec[2] = tempVec[3];
            Assert::IsTrue(tempVec[0] == 3 && tempVec[1] == 2 && tempVec[2] == 1 && tempVec[3] == 1);
        }

        TEST_METHOD(GLOBALS)
        {
            Vector4 vecZero = Vector4::zero;
            Vector4 vecOne = Vector4::one;
            Vector4 vecHalf = Vector4::half;

            Assert::IsTrue(vecZero.x == 0 && vecZero.y == 0 && vecZero.z == 0 && vecZero.w == 0);
            Assert::IsTrue(vecOne.x == 1 && vecOne.y == 1 && vecOne.z == 1 && vecOne.w == 1);
            Assert::IsTrue(vecHalf.x == 0.5f && vecHalf.y == 0.5f && vecHalf.z == 0.5f && vecHalf.w == 0.5f);
        }

        TEST_METHOD(FUNCTIONS)
        {
            Vector4 temp = Vector4(2, 7, 1, 1);
            Assert::AreEqual(temp.Magnitude(), sqrtf(55));

            temp = Vector4(10, 0, 0, 0);
            Assert::IsTrue(temp.Normalized() == Vector4(1, 0, 0, 0));

            temp = Vector4(2, 4, 3, 2);
            Assert::AreEqual(temp.Cross(Vector4(3, 5, 0, 1)), 28.f);

            Vector4 lerp = Vector4::Lerp(temp, Vector4(4, 8, 6, 4), 0.25f);
            Assert::IsTrue(lerp.x == 2.5f && lerp.y == 5 && lerp.z == 3.75f && lerp.w == 2.5f);

            float dist = Vector4::Distance(temp, Vector4(3, 5, 4, 3));
            Assert::AreEqual(dist, sqrtf(4));
        }
    };
}