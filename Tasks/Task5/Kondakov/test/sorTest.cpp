#include <gtest/gtest.h>
#include <iostream>
#include "../sort.h"

class SorterTest : public testing::Test {
public:
	SortInterface * sorter;
	SorterTest() {
		sorter;
	}
};

TEST_F(SorterTest, sorting_1) {
	CompareToolReverse ccc;
	SwapToolTEST sss;
	sorter = new BubbleSort(ccc, sss);
	for (int size = 1; size < 10; ++size) {
		int* v = new int[size];
		int* u = new int[size];
		for (int i = size - 1; i >= 0; --i) { v[i] = -1; u[i] = v[i]; };
		sorter->Sort(v, size);
		std::sort(u, u + size);
		for (int i = 0; i < size; ++i) { EXPECT_EQ(u[i], v[i]); }
	}
}

TEST_F(SorterTest, sorting_2) {
	CompareToolReverse ccc;
	SwapToolTEST sss;
	sorter = new QuickSort(ccc, sss);
	for (int size = 1; size < 10; ++size) {
		int* v = new int[size];
		int* u = new int[size];
		for (int i = size - 1; i >= 0; --i) { v[i] = -1; u[i] = v[i]; };
		sorter->Sort(v, size);
		std::sort(u, u + size);
		for (int i = 0; i < size; ++i) { EXPECT_EQ(u[i], v[i]); }
	}
}