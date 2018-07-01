#include "stdafx.h"
#include "CppUnitTest.h"
#include "../1rst/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public: 
		TEST_METHOD(TestFileOutAndConsoleOut)
		{
			FileLogger ft("ex");

			int a = 130;
			try {
				for (int i = 13; i > 5; i--) {
					if (i == 0) throw logic_error("DivideByZeroException");
					a /= i;
					ft.info(0, "a = " + to_string(a));
				}
			}
			catch (exception& e) {
				(ft.error(-1, e.what()));
			}
		}

		TEST_METHOD(TestFileOut1)
		{
			FileLogger ft("ex");

			int a = 130;
			for (int i = 13; i > 6; i--) {
				a /= i;
				(ft.info(0, "a = " + std::to_string(a)));
			}
		}

		TEST_METHOD(TestFileOut2)
		{
			FileLogger ft("ex");

			int a = 130;
			for (int i = 13; i > 7; i--) {
				a /= i;
				(ft.info(0, "a = " + std::to_string(a)));
			}
		}

		TEST_METHOD(TestConsoleOut1)
		{
			ConsoleLogger ct;

			int a = 130;
			for (int i = 13; i > 8; i--) {
				a /= i;
				(ct.info(0, "a = " + std::to_string(a)));
			}
		}

		TEST_METHOD(TestConsoleOut2)
		{
			ConsoleLogger ct;

			int a = 130;
			for (int i = 13; i > 9; i--) {
				a /= i;
				(ct.info(0, "a = " + std::to_string(a)));
			}
		}

	};
}