#include <gtest/gtest.h>
#include <iostream>
#include "main.cpp"
#include <string>
using namespace std;

class DequeTest : public testing::Test {
public:
    virtual ~DequeTest() {
        delete deque;
    }

    virtual void SetUp(){

        deque = new StaticDeque<int>(7);
    }
    StaticDeque<int>*  deque;
};

TEST_F(DequeTest, isEmpty){
    EXPECT_EQ(0, deque->getSize());
}

TEST_F(DequeTest, checkRight){
    deque->pushRight(777);
    EXPECT_EQ(777, *deque->Right());
}

TEST_F(DequeTest, checkLeft){
    deque->pushLeft(888);
    EXPECT_EQ(888, *deque->Left());
}

TEST_F(DequeTest, emptyNoThrow){
    EXPECT_NO_THROW(deque->popLeft());
    EXPECT_NO_THROW(deque->popRight());
    EXPECT_NO_THROW(deque->Left());
    EXPECT_NO_THROW(deque->Right());
    EXPECT_NO_THROW(deque->getSize());
}

TEST_F(DequeTest, popRight){
    deque->pushRight(777);
    deque->pushRight(888);
    deque->popRight();
    EXPECT_EQ(777, *deque->Right());
}

TEST_F(DequeTest, popLeft){
    deque->pushLeft(777);
    deque->pushLeft(888);
    deque->popLeft();
    EXPECT_EQ(777, *deque->Left());
}
