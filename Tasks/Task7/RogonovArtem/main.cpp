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
    cout << "Expected values t3: 0, 10, 20, 30, 40" << endl;
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
/*
    for (int i = 10; i < 19; i++)
    {
        s2.push(i);
    } for (int i = 0; i < 10; i++)
    {
        s1.push(i);
        s3.push(i * 10);
    }
    s1.printStack();

    cout << endl;

    s3.printStack();

    cout << endl;
    s2.printStack();

    cout << endl;
    cout << "s1, s3" << endl;
    cout << endl;

     for (int i = 0; i < 17; i++)
    {
        s1.pop();
        s3.pop();
    }
    s1.printStack();

    cout << endl;

    s3.printStack();

    for (int i = 0; i < 11; i++)
    {
        s1.push(i);
        s3.push(i * 10);
    }
    s1.printStack();

    cout << endl<<s1.getStackSize();

    s3.printStack();

    cout << endl<<s3.getStackSize();

*/
    return 0;
}
