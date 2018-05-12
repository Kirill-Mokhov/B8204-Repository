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

TEST_F(SorterTest, error_test){

}