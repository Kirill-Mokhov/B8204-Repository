#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../Runner.h"
#include "vector";

class RunnerTest : public testing::Test {
public:
    Runner runner;
    RunnerTest(){
        runner;
    }

};

TEST_F(RunnerTest, crash_test)
{
    Printer printer( "ヽ(o＾▽＾o)ノ");
    ComparatorLess less;
    ComparatorBigger bigger;
    ComparatorDivisibilityBy2 divisibilityBy2;
    FillerRandom* filler;
    vector<Sorter*> sorters = {new BubbleSort(less), new BubbleSort(bigger), new BubbleSort(divisibilityBy2), new ShakerSort(less), new BubbleSort(bigger), new ShakerSort(divisibilityBy2)};
    Runner runner;

    for(Sorter* sorter : sorters) {
        for (int size = 1; size < 100; ++size) {
            int *v = new int[size];
            filler = new FillerRandom(1, size * 10);
            EXPECT_NO_THROW(runner.run(*filler, printer, *sorter, v, size));
        }
    }

}