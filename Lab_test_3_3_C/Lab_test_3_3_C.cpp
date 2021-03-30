#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_3_3_C/FuzzyNumber.cpp"
#include "../Lab_3_3_C/Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Labtest33C
{
	TEST_CLASS(Labtest33C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber A(3.5, 1.2, 7.9), B(4.3, 2.0, 8.4);
			FuzzyNumber C = A + B;
			Assert::AreEqual(C.GetX(), 7.8);
		}
	};
}
