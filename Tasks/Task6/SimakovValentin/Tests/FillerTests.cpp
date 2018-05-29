#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../Filler.h"

class FillerTest : public testing::Test {
public:
    int* v;
    FillerInterface* filler;
    FillerTest(){
        filler;
    }
};

TEST_F(FillerTest, FillerRandom_create){
    for(int j(10), i(0); j >= 0, i < 10; --j, ++i){
        if(i <= j) EXPECT_NO_THROW(FillerRandom(i,j));
        else EXPECT_THROW(FillerRandom(i,j), invalid_argument);
    }
}

TEST_F(FillerTest, FillerRandom_fill){
    for(int i = 1; i < 10; ++i){
        int* v = new int[i];
        filler = new FillerRandom(0, i);
        EXPECT_NO_THROW(filler->fill(v, i));
    }
}