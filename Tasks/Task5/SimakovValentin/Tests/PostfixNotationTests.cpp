#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../PostfixNotation.h"

class PostfixNotationTest : public testing::Test {
public:
    PostfixNotationExpression* postfixExpression;
    PostfixNotationConveter postfixConverter;
    PostfixNotationTest(){
        postfixExpression;
        postfixConverter;
    }
};

TEST_F(PostfixNotationTest, SimpleDigit){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("4"));
    EXPECT_EQ(4, postfixExpression->value());
}

TEST_F(PostfixNotationTest, SimpleExpressionPlus){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("2+2"));
    EXPECT_EQ(4, postfixExpression->value());
}

TEST_F(PostfixNotationTest, SimpleExpressionMinus){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("2-4"));
    EXPECT_EQ(-2, postfixExpression->value());
}

TEST_F(PostfixNotationTest, SimpleExpressionTimes){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("2*4"));
    EXPECT_EQ(8, postfixExpression->value());
}

TEST_F(PostfixNotationTest, ComplexExpressionNoBracketsPlusTimes){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("2*2*2+2*2+2+2"));
    EXPECT_EQ(16, postfixExpression->value());
}

TEST_F(PostfixNotationTest, ComplexExpressionNoBracketsMinusTimes){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("5*2*2-2*2-2*2"));
    EXPECT_EQ(12, postfixExpression->value());
}

TEST_F(PostfixNotationTest, ComplexExpressionBracketsPlusTimes){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("(2+2)*2"));
    EXPECT_EQ(8, postfixExpression->value());
}

TEST_F(PostfixNotationTest, ComplexExpressionBracketsMinusTimes){
    postfixExpression = new PostfixNotationExpression(postfixConverter.convert("5-2*(2-2)*2-3"));
    EXPECT_EQ(2, postfixExpression->value());
}

TEST_F(PostfixNotationTest, ThrowNoRightBrackets){
    EXPECT_THROW(postfixConverter.convert("5-2*(2-2*2-3"), std::logic_error);
}

TEST_F(PostfixNotationTest, ThrowNoLeftBrackets){
    EXPECT_THROW(postfixConverter.convert("5-2*2-2)*2-3"), std::logic_error);
}

