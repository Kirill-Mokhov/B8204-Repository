#include <iostream>
#include "StackH.h"

using namespace std;

int main()
{
    /*
    Stack<int> s1(6);
    Stack<int> s2(8);
    for (int i = 0; i < 7; i++)
    {
        s1.push(i);
    }
    s1.printStack();

    s2 = s1;

    s2.printStack();
    */

//TEST
    Stack<int> TS(4);

    cout << "Testing PUSH" << endl;

    for (int i = 0; i < 7; i++)
    {
        TS.push(i);
    }
    TS.printStack();
    cout << endl;


    for (int i = 0; i < 10; i++)
    {
        cout << "Testing POP" << endl;
        TS.pop();
        TS.printStack();
        cout << endl;
    }

    cout << endl;

    return 0;
}
