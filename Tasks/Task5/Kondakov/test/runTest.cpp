#include <gtest/gtest.h>
#include <iostream>
#include "../run.h"
#include "vector";

class RunnerTest : public testing::Test {
public:
	Runner runner;
	RunnerTest() {
		runner;
	}

};

TEST_F(RunnerTest, crash_test)
{
	PointersPrinter printer;
	CompareToolReverse compare1;
	SwapToolTEST swap1;
	FillerRandom* filler;

	vector<SortInterface*> sorters = { new BubbleSort(compare1, swap1), new ShakerSort(compare1, swap1), new QuickSort(compare1, swap1) };
	Runner runner;

	for (SortInterface* sorter : sorters) {
		for (int size = 1; size < 100; ++size) {
			int *v = new int[size];
			filler = new FillerRandom();
			EXPECT_NO_THROW(runner.run(*filler, *sorter, printer, v, size));
		}
	}

}