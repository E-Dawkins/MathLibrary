#include "pch.h"
#include "CppUnitTest.h"
#include "../TestLib/TestLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(BasicTest)
		{
			int temp = Sum(1, 2);
			Assert::AreEqual(temp, 3);
		}
	};
}
