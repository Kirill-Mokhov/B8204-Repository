#include <gtest/gtest.h>
#include <iostream>
#include "qe.cpp"
#include <string>
using namespace std;

class QueueTest : public testing::Test {
public:
	virtual ~QueueTest() {
		delete Queue;
	}

	virtual void SetUp() {

		Queue = new Queue<int>(7);
	}
	Queue<int>*  Queue;
};

TEST_F(QueueTest, isEmpty) {
	EXPECT_EQ(0, Queue->length());
}


TEST_F(QueueTest, emptyNoThrow) {
	EXPECT_NO_THROW(Queue->popElement());
	EXPECT_NO_THROW(Queue->length());
	EXPECT_NO_THROW(Queue->pushElement());
}

TEST_F(QueueTest, popElement) {
	Queue->pushElement(777);
	Queue->pushElement(888);
	Queue->pushElement();
	EXPECT_EQ(777, *Queue->Right());
}