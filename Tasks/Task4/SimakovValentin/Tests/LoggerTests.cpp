#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../ConsoleLogger.h"
#include "../FileLogger.h"

class ConsoleLoggerTest : public testing::Test {
public:
    ConsoleLogger cl;
    ConsoleLoggerTest(){
        cl;
    }
};

class FileLoggerTest : public testing::Test {
public:
    FileLogger fl;
    FileLoggerTest(){
        fl;
    }
};

TEST_F(ConsoleLoggerTest, info_test){
    int a = 120;
    for (int i = 5; i > 0; i--) {
        a /= i;
        EXPECT_NO_THROW(cl.info(0, "a = " + std::to_string(a)));
    }
}

TEST_F(ConsoleLoggerTest, error_test){
    int a = 120;
    try {
        for (int i = 5; i > -2; i--) {
            if(i == 0) throw std::logic_error("DivideByZeroException");
            a /= i;
            cl.info(0, "a = " + std::to_string(a));
        }
    }catch(std::exception& e){
        EXPECT_NO_THROW(cl.error(-1, e.what()));
    }
}

TEST_F(ConsoleLoggerTest, output){
    time_t timer = time(NULL);
    char sTime[80];
    strftime(sTime, 80, "%d/%m/%Y %X(%Z)", gmtime(&timer));

    std::string t = sTime;
    std::string s2 = "INFO: [" + t +"] Code: 0 Message: Test";
    std::cout << "--" << std::endl;
    cl.info(0, "Test");
    std::cout << s2 << std::endl;
    std::cout << "**" << std::endl;

    EXPECT_EQ(cl.info(0, "Test"), s2);
}
