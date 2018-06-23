#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../ConsoleLogger.h"
#include "../FileLogger.h"

class FileLoggerTest : public testing::Test {
public:
    FileLogger fl;
    FileLoggerTest(){
        fl;
    }
};

TEST_F(FileLoggerTest, info_test){
    int a = 120;
    for (int i = 5; i > 0; i--) {
        a /= i;
        EXPECT_NO_THROW(fl.info(0, "a = " + std::to_string(a)));
    }
}

TEST_F(FileLoggerTest, error_test){
    int a = 120;
    try {
        for (int i = 5; i > -2; i--) {
            if(i == 0) throw std::logic_error("DivideByZeroException");
            a /= i;
            fl.info(0, "a = " + std::to_string(a));
        }
    }catch(std::exception& e){
        EXPECT_NO_THROW(fl.error(-1, e.what()));
    }
}

TEST_F(FileLoggerTest, output) {
    time_t timer = time(NULL);

    std::ifstream file("../log.txt");

    std::string s(fl.info(0, "Test"));
    std::string fl_message;

    while(getline(file,fl_message));

    EXPECT_EQ(s, fl_message);
}

