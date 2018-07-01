#include <iostream>
#include "rpn.h"
#include <gtest/gtest.h>
using namespace std;

int main() {
    //string input; //enter here

    return RUN_ALL_TESTS();

    /*try {
        getline(cin, input, '\n');
        string rpn = rpn::convert(input);
        cout << "RPN = " << rpn << endl;
        double result = rpn::calculate(rpn);
        cout << "Result = " <<result;
        return 0;
    } catch (const runtime_error *&err) {
        cerr << err->what();
        return 1;
    }*/
}