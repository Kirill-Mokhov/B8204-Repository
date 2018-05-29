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

TEST_F(PrinterTest, print){
    printer = new Printer( "ヽ(o＾▽＾o)ノ");
    for(int size = 1; size < 10; ++size) {
        int *v = new int[size];
        for (int i = 0; i < size; ++i) v[i] = i * size;
        EXPECT_NO_THROW(printer->print(v, size));
    }
}