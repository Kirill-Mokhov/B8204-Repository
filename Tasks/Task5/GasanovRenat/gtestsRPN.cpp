#include <iostream>
#include "rpn.h"
//#include "rpn.cpp"
#include <gtest/gtest.h>
#include <string>

using namespace std;

class PostfixNotationTest : public testing::Test {
public:
    double postfixResult;
    string postfixExpression;

    rpn RPN;
    PostfixNotationTest(){
        RPN;
    }
};

TEST_F(PostfixNotationTest, SimpleDigit){
    postfixExpression = RPN.convert("4");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(4, postfixResult);
    EXPECT_EQ("4", postfixExpression);
}

TEST_F(PostfixNotationTest, SimpleExpressionPlus){
    postfixExpression = RPN.convert("2+2");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(4, postfixResult);
    EXPECT_EQ("2 2 +", postfixExpression);
}

TEST_F(PostfixNotationTest, SimpleExpressionMinus){
    postfixExpression = RPN.convert("2-4");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(-2, postfixResult);
    EXPECT_EQ("2 4 -", postfixExpression);
}

TEST_F(PostfixNotationTest, SimpleExpressionTimes){
    postfixExpression = RPN.convert("2*4");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(8, postfixResult);
    EXPECT_EQ("2 4 *", postfixExpression);
}

TEST_F(PostfixNotationTest, ComplexExpressionNoBracketsPlusTimes){
    postfixExpression = RPN.convert("2*2*2+2*2+2+2");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(16, postfixResult);
    EXPECT_EQ("2 2 * 2 * 2 2 * 2 + 2 + +", postfixExpression);
}

TEST_F(PostfixNotationTest, ComplexExpressionNoBracketsMinusTimes){
    postfixExpression = RPN.convert("5*2*2-2*2");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(16, postfixResult);
    EXPECT_EQ("5 2 * 2 * 2 2 * -", postfixExpression);
}

TEST_F(PostfixNotationTest, ComplexExpressionBracketsPlusTimes){
    postfixExpression = RPN.convert("( 2 + 2 ) * 2");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(8, postfixResult);
    EXPECT_EQ("2 2 + 2 *", postfixExpression);
}

TEST_F(PostfixNotationTest, EmptyBrackets){
    EXPECT_NO_THROW(RPN.convert("()"));
}

TEST_F(PostfixNotationTest, SeveralDigits){
    postfixExpression = RPN.convert("222+333*123");
    postfixResult = RPN.calculate(postfixExpression);

    EXPECT_EQ(41181, postfixResult);
    EXPECT_EQ("222 333 123 * +", postfixExpression);
}