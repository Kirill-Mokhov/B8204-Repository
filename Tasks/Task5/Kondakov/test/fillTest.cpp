#include <gtest/gtest.h>
#include <iostream>
#include "../fill.h"

class FillerTest : public testing::Test {
public:
	int* v;
	FillerInterface* filler;
	FillerTest() {
		filler;
	}
};

TEST_F(FillerTest, FillerRandom_create) {
	EXPECT_NO_THROW(FillerRandom());
}

TEST_F(FillerTest, FillerRandom_fill) {
	for (int i = 1; i < 10; ++i) {
		int* v = new int[i];
		filler = new FillerRandom();
		EXPECT_NO_THROW(filler->fill(v, i));
	}
}

TEST_F(FillerTest, FillerManual_create) {
	EXPECT_NO_THROW(FillerManual());
}