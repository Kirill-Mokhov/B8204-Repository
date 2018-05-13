#include <iostream>
#include <gtest/gtest.h>
#include "PostfixNotation.h"

int main() {
    PostfixNotationConveter RPN;
    PostfixNotationExpression c(RPN.convert("2+2*2"));

    std::cout << c.value() << std::endl;
    std::cout << RPN.convert("2+2+1*9-(0*8)*8");
    return 0;
}
