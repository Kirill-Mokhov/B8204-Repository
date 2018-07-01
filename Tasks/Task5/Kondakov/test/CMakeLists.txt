cmake_minimum_required(VERSION 3.10)
project(QickSortOOP)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(libs/googletest)

include_directories(libs/googletest/googletest/include)

add_executable(QickSortOOP main.cpp run.h fill.h print.h sort.h swap.h compare.h tests/printerTests.cpp tests/fillerTests.cpp tests/runnerTests.cpp tests/sorterTests.cpp tests/compareTests.cpp tests/swapTests.cpp)
set(SOURCE_FILES run.h sort.h swap.h compare.h print.h fill.h main.cpp)
target_link_libraries(QickSortOOP gtest)