#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../Sorter.h"

class SorterTest : public testing::Test {
public:
    SorterInterface* sorter;
    SorterTest(){
        sorter;
    }
};

TEST_F(SorterTest, sorting_1){
    ComparatorLess cless;
    sorter = new BubbleSort(cless);
    for(int size = 1; size < 10; ++size) {
        int* v = new int[size];
        int* u = new int[size];
        for (int i = size - 1; i >= 0; --i) {v[i] = i * size; u[i] = v[i];};
        sorter->sort(v, size);
        std::sort(u, u+size);
        for (int i = 0; i < size; ++i) {EXPECT_EQ(u[i], v[i]);}
    }
}

TEST_F(SorterTest, sorting_2){
    ComparatorLess cless;
    sorter = new BubbleSort(cless);
    for(int size = 1; size < 10; ++size) {
        int* v = new int[size];
        int* u = new int[size];
        for (int i = size - 1; i >= 0; --i) {v[i] = (i - size) * size; u[i] = v[i];};
        sorter->sort(v, size);
        std::sort(u, u+size);
        for (int i = 0; i < size; ++i) {EXPECT_EQ(u[i], v[i]);}
    }
}

TEST_F(SorterTest, sorting_3){
    ComparatorLess cless;
    sorter = new BubbleSort(cless);
    for(int size = 1; size < 10; ++size) {
        int* v = new int[size];
        int* u = new int[size];
        for (int i = size - 1; i >= 0; --i) {v[i] = -1; u[i] = v[i];};
        sorter->sort(v, size);
        std::sort(u, u+size);
        for (int i = 0; i < size; ++i) {EXPECT_EQ(u[i], v[i]);}
    }
}