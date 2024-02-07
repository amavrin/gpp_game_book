#include "pch.h"
#include "CppUnitTest.h"
#include "..\GuessMyNumber2\guess_my_number.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rnd = -1;
			auto res = rnd_between(0, 1, rnd);
			Assert::IsTrue(res == FUNC_OK);
			Assert::IsTrue(0 <= rnd && rnd <= 1);
		}

		TEST_METHOD(TestMethod2)
		{
			int rnd = -1;
			auto res = rnd_between(0, 0, rnd);
			Assert::IsTrue(res == FUNC_OK);
			Assert::IsTrue(0 == rnd);
		}

		TEST_METHOD(TestMethod3)
		{
			int rnd = -1;
			auto res = rnd_between(0, -1, rnd);
			Assert::IsTrue(res == FUNC_ERR);
		}
	};
}
