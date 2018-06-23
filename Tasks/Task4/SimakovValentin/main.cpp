#include <iostream>
#include "Logger.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

int main() {
    FileLogger l;
    return RUN_ALL_TESTS();
}