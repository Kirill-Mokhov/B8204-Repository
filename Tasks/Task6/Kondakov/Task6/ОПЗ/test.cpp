#include <iostream>
#include "opz.h"
#include "opz.cpp"
#include <gtest/gtest.h>
#include <string>

using namespace std;

class PostfixNotationTest : public testing::Test {
public:
	double postfixResult;
	string postfixExpression;

	opz opz;
	PostfixNotationTest() {
		opz;
	}
};

TEST_F(PostfixNotationTest, SimpleDigit) {
	postfixExpression = opz.convert("4");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(4, postfixResult);
	EXPECT_EQ("4", postfixExpression);
}

TEST_F(PostfixNotationTest, SimpleExpressionPlus) {
	postfixExpression = opz.convert("2+2");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(4, postfixResult);
	EXPECT_EQ("2 2 +", postfixExpression);
}

TEST_F(PostfixNotationTest, SimpleExpressionMinus) {
	postfixExpression = opz.convert("2-4");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(-2, postfixResult);
	EXPECT_EQ("2 4 -", postfixExpression);
}

TEST_F(PostfixNotationTest, SimpleExpressionTimes) {
	postfixExpression = opz.convert("2*4");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(8, postfixResult);
	EXPECT_EQ("2 4 *", postfixExpression);
}

TEST_F(PostfixNotationTest, ComplexExpressionNoBracketsPlusTimes) {
	postfixExpression = opz.convert("2*2*2+2*2+2+2");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(16, postfixResult);
	EXPECT_EQ("2 2 * 2 * 2 2 * 2 + 2 + +", postfixExpression);
}

TEST_F(PostfixNotationTest, ComplexExpressionNoBracketsMinusTimes) {
	postfixExpression = opz.convert("5*2*2-2*2");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(16, postfixResult);
	EXPECT_EQ("5 2 * 2 * 2 2 * -", postfixExpression);
}

TEST_F(PostfixNotationTest, ComplexExpressionBracketsPlusTimes) {
	postfixExpression = opz.convert("( 2 + 2 ) * 2");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(8, postfixResult);
	EXPECT_EQ("2 2 + 2 *", postfixExpression);
}

TEST_F(PostfixNotationTest, EmptyBrackets) {
	EXPECT_NO_THROW(opz.convert("()"));
}

TEST_F(PostfixNotationTest, SeveralDigits) {
	postfixExpression = opz.convert("222+333*123");
	postfixResult = opz.calculate(postfixExpression);

	EXPECT_EQ(41181, postfixResult);
	EXPECT_EQ("222 333 123 * +", postfixExpression);
}