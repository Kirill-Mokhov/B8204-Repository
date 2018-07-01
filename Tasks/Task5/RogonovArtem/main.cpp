#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
//TEST
    //int a;
    Converter converterT1;
    Postfix* postfixT1;
    postfixT1 = new Postfix(converterT1.Convert("2+2"));
    cout << "Test 1: Expected result: 4" << endl << "Test 1: OUTPUT RESULT " << postfixT1->Perform() << endl;

    Converter converterT2;
    Postfix* postfixT2;
    postfixT2 = new Postfix(converterT2.Convert("(2+2)*2"));
    cout << "Test 2: Expected result: 8" << endl << "Test 2: OUTPUT RESULT " << postfixT2->Perform() << endl;

    Converter converterT3;
    Postfix* postfixT3;
    postfixT3 = new Postfix(converterT3.Convert("2+2*2+5/5+4/2+5*9-12/4+(2+2)"));
    cout << "Test 3: Expected result: 55" << endl << "Test 3: OUTPUT RESULT " << postfixT3->Perform() << endl;

    Converter converterT4;
    Postfix* postfixT4;
    postfixT4 = new Postfix(converterT4.Convert("(11-5)/2+5*2-6"));
    cout << "Test 4: Expected result: 7" << endl << "Test 4: OUTPUT RESULT " << postfixT4->Perform() << endl;
/*
    Converter converterT5;
    Postfix* postfixT5;
    postfixT5 = new Postfix(converterT5.Convert("(11-5/2+5*2-6"));
    cout << "Test 5: Expected result: ERROR" << endl << "Test 5: OUTPUT RESULT " << postfixT5->Perform() << endl;
*/
/*
    Converter converterT6;
    Postfix* postfixT6;
    postfixT6 = new Postfix(converterT6.Convert("11-5)/2+5*2-6"));
    cout << "Test 6: Expected result: ERROR" << endl << "Test 6: OUTPUT RESULT " << postfixT4->Perform() << endl;
*/


    return 0;
}
