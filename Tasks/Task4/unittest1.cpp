#include "stdafx.h"
#include "CppUnitTest.h"
#include "../logger/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public: //ѕсевдотесты
		TEST_METHOD(TestFileOutAndConsoleOut)
		{
			FileLogger fl("ex");
			
			int a = 120;
			try {
				for (int i = 5; i > -2; i--) {
					if (i == 0) throw logic_error("DivideByZeroException");
					a /= i;
					fl.info(0, "a = " + to_string(a));
				}
			}
			catch (exception& e) {
				(fl.error(-1, e.what()));
			}
		}

		TEST_METHOD(TestFileOut1)
		{
			FileLogger fl("ex");

			int a = 120;
			for (int i = 5; i > 0; i--) {
				a /= i;
				(fl.info(0, "a = " + std::to_string(a)));
			}
		}

		TEST_METHOD(TestFileOut2)
		{
			FileLogger fl("ex");

			int a = 120;
			for (int i = 5; i > 0; i--) {
				a /= i;
				(fl.info(0, "a = " + std::to_string(a)));
			}
		}

		TEST_METHOD(TestConsoleOut1)
		{
			ConsoleLogger cl;

			int a = 120;
			for (int i = 5; i > 0; i--) {
				a /= i;
				(cl.info(0, "a = " + std::to_string(a)));
			}
		}

		TEST_METHOD(TestConsoleOut2)
		{
			ConsoleLogger cl;

			int a = 120;
			for (int i = 5; i > 0; i--) {
				a /= i;
				(cl.info(0, "a = " + std::to_string(a)));
			}
		}

	};
}