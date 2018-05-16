#include <iostream>
#include "RingDeque.cpp"

int main() {
    RingDeque<int> d1(10, "WHEEL");
    RingDeque<int> d2(6, "WHEEL1");


    for (int i = 0; i < 17; i++)
    {
        //d1.PushFront(i) ;
        d1.PushBack(i*10);
        //  d1.PushFront(i*5);
    }
    d1.print();

    for (int i = 0; i < 6; i++)
    {
        //d1.PushFront(i) ;
        d1.PopBack();

        d2.PushFront( d1.PeekBack()/2);
        d1.PushFront(d1.PeekBack()/2);
    }
    d1.print();
    d2.print();

    RingDeque<int> d3(d1);
    d3.print();
    d2=d3;

    d2.print();
    d3.print();

  /*  d1.print();
    d2.print();
    d1 = d2;
    d1.print();*/

/*56
 * Test 3.1, 3.2, 3.3
 *
    for (int i = 0; i < 7; i++)
    {
        if (first.PushFront(i) == -301) cout << "i = " << i << " " << first.getName() << " is full" << endl;
    }
    cout << "Length of " << first.getName() << " = " << first.getLength() << endl;
    first.print();

    cout << endl << endl;

    for (int i = 0; i < 7; i++)
    {
        if (first.PopFront() == -315) cout << "i = " << i << " " << first.getName() << " is empty" << endl;

    }
    cout << "Length of " << first.getName() << " = " << first.getLength() << endl;
*/

/*
    * Test 2.1, 2.2, 2.3
    * Test 5.1, 5.2, 5.3

    for (int i = 0; i < 7; i++)
    {
        if (first.PushBack(i)) cout << "i = " << i << " " << first.getName() << " is full" << endl;
    }
    cout << "Length of " << first.getName() << " = " << first.getLength() << endl;
    first.print();

    cout << endl << endl;

    for (int i = 0; i < 7; i++)
    {
        if (first.PopBack() == -315) cout << "i = " << i << " " << first.getName() << " is empty" << endl;

    }
    cout << "Length of " << first.getName() << " = " << first.getLength() << endl;

*/

    return 0;
}