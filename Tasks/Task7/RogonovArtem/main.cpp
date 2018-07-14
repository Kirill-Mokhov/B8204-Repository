#include <iostream>
#include "StackH.h"

using namespace std;

int main()
{
    Stack<int> t1(11);
    Stack<int> t2(11);
    Stack<int> t3(5);

//////Testing PUSH and PRINT
    for (int i = 0; i < 10; i++)
    {
        t1.push(i);
        t3.push(i * 10);
    }
    cout << "Testing(t1) right PUSH and PRINT" << endl;
    cout << "Expected values t1: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9" << endl;
    cout << "Out values t1: " << endl;
    t1.printStack();

    cout << endl;
    cout << "Testing(t3) PUSH and PRINT (Dim < IN) " << endl;
    cout << "Expected values t3: 0, 10, 20, 30, 40" << endl;
    cout << "Out values t3: " << endl;
    t3.printStack();
    cout << endl;

//////Testing POP and PRINT
    t3.pop();
    cout << "Testing(t3) right POP and PRINT" << endl;
    cout << "Expected values t3: 0, 10, 20, 30" << endl;
    cout << "Out values t3: " << endl;
    t3.printStack();
    cout << endl;

    t3.pop();
    t3.pop();
    t3.pop();
    t3.pop();
    cout << "Testing(t3) right POP and PRINT" << endl;
    cout << "Expected values t3: (Nothing)" << endl;
    cout << "Out values t3: " << endl;
    t3.printStack();
    cout << endl;

    t3.pop();
    cout << "Testing(t3) POP and PRINT (EMPTY POP)" << endl;
    cout << "Expected values t3: (Nothing)" << endl;
    cout << "Out values t3: " << endl;
    t3.printStack();
    cout << endl;

//////Testing OPERATOR =
    t3 = t1;
    cout << "Testing(t3) OPERATOR = " << endl;
    cout << "Expected values t3: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9" << endl;
    cout << "Out values t3: " << endl;
    t3.printStack();
    cout << endl;

//////Testing T
    Stack<double> t4(5);
    t4.push(1.5);
    cout << "Testing type. No Throw. 1.5" << endl;
    t4.printStack();
    cout << endl;

//////Testing Pop (Nu tip hz kak po-drugomu proverit')
    t2.push(1);
    t2.push(2);
    //t2.printStack();
    //cout << endl;

    t2.pop();
    if (t2.StackE[0] != 1)
        cout << "Testing(1) pop return. Wrong Pop(Unexpected)" << endl;
    else
        cout << "Testing(1) pop return. Right Pop(Expected)" << endl;

        cout << endl;

    t2.push(2);
    t2.push(3);

    t2.pop();
    if (t2.StackE[1] != 1)
        cout << "Testing(2) pop return. Wrong Pop(Expected)" << endl;
    else
        cout << "Testing(2) pop return. Right Pop(Unexpected)" << endl;

    return 0;
}
