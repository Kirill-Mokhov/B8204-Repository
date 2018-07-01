#include <gtest/gtest.h>
#include <iostream>
#include "../compare.h"

class ComparatorTest : public testing::Test {
public:
	CompareInterface * comparator;
	ComparatorTest() {
		comparator;
	}
};

TEST_F(ComparatorTest, CompareToolReverse_1) {
	comparator = new CompareToolReverse();
	for (int i = 1; i < 10; ++i)
		EXPECT_TRUE(!(0 < i) || (comparator->Compare(0, i) == -1));
}

TEST_F(ComparatorTest, CompareToolReverse_2) {
	comparator = new CompareToolReverse();
	for (int i = 1; i < 10; ++i)
		EXPECT_TRUE(!(i < 0) || (comparator->Compare(i, 0) == 1));
}

TEST_F(ComparatorTest, CompareToolReverse_3) {
	comparator = new CompareToolReverse();
	for (int i = -10; i < 10; ++i)
		EXPECT_TRUE(comparator->Compare(i, i) == 0);
}

TEST_F(ComparatorTest, CompareTool_1) {
	comparator = new CompareTool();
	for (int i = 1; i < 10; ++i)
		EXPECT_TRUE(!(0 > i) || (comparator->Compare(0, i) == 1));
}

TEST_F(ComparatorTest, CompareTool_2) {
	comparator = new CompareTool();
	for (int i = 1; i < 10; ++i)
		EXPECT_TRUE(!(i > 0) || (comparator->Compare(i, 0) == -1));
}

TEST_F(ComparatorTest, CompareTool_3) {
	comparator = new CompareTool();
	for (int i = -10; i < 10; ++i)
		EXPECT_TRUE(comparator->Compare(i, i) == 0);
}