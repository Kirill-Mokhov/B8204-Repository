#include <gtest/gtest.h>
#include <iostream>
#include "../print.h"

class PrinterTest : public testing::Test {
public:
	PrinterInterface * printer;
	PrinterTest() {
		printer;
	}
};


TEST_F(PrinterTest, printing_without_pointers) {
	printer = new StandartPrinter();
	for (int size = 1; size < 10; ++size) {
		int *v = new int[size];
		for (int i = 0; i < size; ++i) v[i] = i * size;
		EXPECT_NO_THROW(printer->print(v, size));
	}
}