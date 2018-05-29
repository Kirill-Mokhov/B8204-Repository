#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../Comparator.h"

class ComparatorTest : public testing::Test {
public:
    ComparatorInterface* comparator;
    ComparatorTest(){
        comparator;
    }
};

TEST_F(ComparatorTest, ComparatorLess_less){
    comparator = new ComparatorLess();
    for(int i = 1; i < 10; ++i)
        EXPECT_TRUE(!(0 < i) || (comparator->compare(0,i) == 1));
}

TEST_F(ComparatorTest, ComparatorLess_bigger){
    comparator = new ComparatorLess();
    for(int i = 1; i < 10; ++i)
        EXPECT_TRUE(!(i < 0) || (comparator->compare(i,0) == -1));
}

TEST_F(ComparatorTest, ComparatorLess_equal){
    comparator = new ComparatorLess();
    for(int i = -10; i < 10; ++i)
        EXPECT_TRUE(comparator->compare(i, i) == 0);
}

TEST_F(ComparatorTest, ComparatorBigger_less){
    comparator = new ComparatorBigger();
    for(int i = 1; i < 10; ++i)
        EXPECT_TRUE(!(0 > i) || (comparator->compare(0,i) == -1));
}

TEST_F(ComparatorTest, ComparatorBigger_bigger){
    comparator = new ComparatorBigger();
    for(int i = 1; i < 10; ++i)
        EXPECT_TRUE(!(i > 0) || (comparator->compare(i,0) == 1));
}

TEST_F(ComparatorTest, ComparatorBigger_equal){
    comparator = new ComparatorBigger();
    for(int i = -10; i < 10; ++i)
        EXPECT_TRUE(comparator->compare(i, i) == 0);
}

TEST_F(ComparatorTest, ComparatorDivisibilityBy2_left){
    comparator = new ComparatorDivisibilityBy2();
    for(int i = 1; i < 10; i+=2)
        EXPECT_EQ(1, comparator->compare(i-1,i));
}

TEST_F(ComparatorTest, ComparatorDivisibilityBy2_right){
    comparator = new ComparatorDivisibilityBy2();
    for(int i = 1; i < 10; i+=2)
        EXPECT_EQ(-1, comparator->compare(i,i-1));
}


TEST_F(ComparatorTest, ComparatorDivisibilityBy2_both){
    comparator = new ComparatorDivisibilityBy2();
    for(int i = 0; i < 10; i+=2)
        EXPECT_EQ(0, comparator->compare(i,i));
}