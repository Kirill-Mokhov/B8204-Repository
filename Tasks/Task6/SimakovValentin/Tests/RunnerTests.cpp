#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../Runner.h"

class RunnerTest : public testing::Test {
public:
    Runner runner;
    RunnerTest(){
        runner;
    }
};

TEST_F(RunnerTest, error_test){

}