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

        TEST_METHOD(MATH_OPERATIONS)
        {
            Vector2 tempVec = Vector2(1, 2);

            // Addition
            tempVec = tempVec + Vector2(2, 1);
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 3);

            tempVec = tempVec + 3;
            Assert::IsTrue(tempVec.x == 6 && tempVec.y == 6);

            tempVec += Vector2(2, 1);
            Assert::IsTrue(tempVec.x == 8 && tempVec.y == 7);

            tempVec += 2;
            Assert::IsTrue(tempVec.x == 10 && tempVec.y == 9);

            // Subtraction
            tempVec = tempVec - Vector2(10, 9);
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0);

            tempVec = tempVec - 3;
            Assert::IsTrue(tempVec.x == -3 && tempVec.y == -3);

            tempVec -= Vector2(2, 1);
            Assert::IsTrue(tempVec.x == -5 && tempVec.y == -4);

            tempVec -= 2;
            Assert::IsTrue(tempVec.x == -7 && tempVec.y == -6);

            // Multiply
            tempVec = tempVec * -1;
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 6);

            tempVec *= 1.5f;
            Assert::IsTrue(tempVec.x == 10.5f && tempVec.y == 9);

            // Division
            tempVec = tempVec / 1.5f;
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 6);

            tempVec /= 2;
            Assert::IsTrue(tempVec.x == 3.5f && tempVec.y == 3);
        }

        TEST_METHOD(MISC_OPERATIONS)
        {
            Vector2 tempVec = Vector2(2.345f);
            std::ostringstream out;
            out << tempVec;
            Assert::AreEqual("(2.345, 2.345)", out.str().c_str());

            Assert::IsFalse(tempVec == Vector2(3, 2));
            Assert::IsTrue(tempVec != Vector2(3, 2));
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

        TEST_METHOD(MATH_OPERATIONS)
        {
            Vector3 tempVec = Vector3(2);

            // Addition
            tempVec = tempVec + Vector3(1, 2, 3);
            Assert::IsTrue(tempVec.x == 3 && tempVec.y == 4 && tempVec.z == 5);

            tempVec = tempVec + 1;
            Assert::IsTrue(tempVec.x == 4 && tempVec.y == 5 && tempVec.z == 6);

            tempVec += 2;
            Assert::IsTrue(tempVec.x == 6 && tempVec.y == 7 && tempVec.z == 8);

            tempVec += Vector3(1, 0, -1);
            Assert::IsTrue(tempVec.x == 7 && tempVec.y == 7 && tempVec.z == 7);

            // Subtraction
            tempVec = tempVec - Vector3(7);
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == 0 && tempVec.z == 0);

            tempVec = tempVec - 1;
            Assert::IsTrue(tempVec.x == -1 && tempVec.y == -1 && tempVec.z == -1);

            tempVec -= 2;
            Assert::IsTrue(tempVec.x == -3 && tempVec.y == -3 && tempVec.z == -3);

            tempVec -= Vector3(-3, 2, -5);
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -5 && tempVec.z == 2);

            //// Multiplication
            tempVec = tempVec * 2.5f;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -12.5f && tempVec.z == 5);

            tempVec *= 2;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -25 && tempVec.z == 10);

            //// Division
            tempVec = tempVec / 2;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -12.5f && tempVec.z == 5);

            tempVec /= 2.5f;
            Assert::IsTrue(tempVec.x == 0 && tempVec.y == -5 && tempVec.z == 2);
        }

        TEST_METHOD(MISC_OPERATIONS)
        {
            Vector3 tempVec = Vector3(1, 2, 3);
            std::ostringstream out;
            out << tempVec;
            Assert::AreEqual("(1, 2, 3)", out.str().c_str());

            Assert::IsFalse(tempVec == Vector3(3, 2, 1));
            Assert::IsTrue(tempVec != Vector3(3, 2, 1));
        }
    };
}