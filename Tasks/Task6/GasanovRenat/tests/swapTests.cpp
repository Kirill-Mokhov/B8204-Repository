#include <gtest/gtest.h>
#include <iostream>
#include "../sort.h"

class SwapTest : public testing::Test {
public:
    SwapToolTEST* swap;
    SwapTest(){
        swap;
    }
};

TEST_F(SwapTest, Swap_No_Error){
    swap = new SwapToolTEST();
    for(int i = 1; i < 10; ++i){
        int elem1 = 10;
        int elem2 = 20;
        swap->Swap(elem1, elem2);
        EXPECT_TRUE((elem1 == 20) && (elem2 = 10));
    }
}

TEST_F(SwapTest, Swap_Error){
    swap = new SwapToolTEST();
    for(int i = 1; i < 10; ++i){
        int elem1 = 10;
        int elem2 = 20;
        swap->Swap(elem1, elem2);
        EXPECT_FALSE((elem1 == 10) && (elem2 = 20));
    }
}