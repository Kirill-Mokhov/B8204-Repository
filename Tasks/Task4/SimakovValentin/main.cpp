#include <iostream>
#include "Logger.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

int main() {
    ConsoleLogger cl;
    cl.info(0, "a = " + std::to_string(1));
    return RUN_ALL_TESTS();
}