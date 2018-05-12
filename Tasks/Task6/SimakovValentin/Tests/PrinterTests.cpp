#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../Printer.h"

class PrinterTest : public testing::Test {
public:
    PrinterInterface* printer;
    PrinterTest(){
        printer;
    }
};

TEST_F(PrinterTest, error_test){

}