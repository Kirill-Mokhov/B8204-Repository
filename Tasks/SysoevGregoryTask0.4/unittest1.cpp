#include "stdafx.h"
#include "CppUnitTest.h"
#include "Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1Lab
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodSum)
		{
			complexNumber a(1);
			complexNumber b(1);
			complexNumber result = a + b;
			complexNumber WeWait(2);
			Assert::AreEqual(result.getPrimaryPath(), WeWait.getPrimaryPath());
			Assert::AreEqual(result.getComplexPath(), WeWait.getComplexPath());
		}
		TEST_METHOD(TestMethodDif) {
			complexNumber a(1, 2);
			complexNumber b(1, 2);
			complexNumber result = a - b;
			complexNumber WeWait(0);
			Assert::AreEqual(result.getPrimaryPath(), WeWait.getPrimaryPath());
			Assert::AreEqual(result.getComplexPath(), WeWait.getComplexPath());
		}
		TEST_METHOD(TestMethodSumR) {
			complexNumber a(1);
			complexNumber result = a + 2;
			complexNumber WeWait(3);
			Assert::AreEqual(result.getPrimaryPath(), WeWait.getPrimaryPath());
			Assert::AreEqual(result.getComplexPath(), WeWait.getComplexPath());
		}
		TEST_METHOD(TestMethodSumL) {
			complexNumber a(1);
			complexNumber result = 3 + a;
			complexNumber WeWait(4);
			Assert::AreEqual(result.getPrimaryPath(), WeWait.getPrimaryPath());
			Assert::AreEqual(result.getComplexPath(), WeWait.getComplexPath());
		}
		TEST_METHOD(TestMethodMul) {
			complexNumber a(1);
			complexNumber b(0);
			complexNumber result = b * a;
			complexNumber WeWait(0);
			Assert::AreEqual(result.getPrimaryPath(), WeWait.getPrimaryPath());
			Assert::AreEqual(result.getComplexPath(), WeWait.getComplexPath());
		}
		TEST_METHOD(TestMethodQuot) {
			complexNumber a(1);
			complexNumber b(0);
			complexNumber result = b / a;
			complexNumber WeWait(0);
			Assert::AreEqual(result.getPrimaryPath(), WeWait.getPrimaryPath());
			Assert::AreEqual(result.getComplexPath(), WeWait.getComplexPath());
		}

	};
}