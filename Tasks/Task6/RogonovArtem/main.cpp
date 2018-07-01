#include <iostream>
#include <ctime>
#include <random>
#include "Runner.h"

using namespace std;

int main()
{
    int size = 10;
    int *arr = new int[size];

//////Test Bubble Sort and Random Filler and Runner//////

/*
    RandomFiller randomFiller(20);
    Equal CompareT;
    BubbleSort bubbleSort(&CompareT);
    Printer printer;

    Runner runner;

    runner.Run(arr, size, randomFiller, bubbleSort, printer);
*/

//////Test Insert Sort and Just Filler and Runner//////
/*
    JustFiller justFiller(13, 5);
    Equal CompareT;
    InsertSort insertSort(&CompareT);
    Printer printer;

    Runner runner;

    cout << "Test Just Filler Expected : 3, 4, 5, 6, 7, 3, 4, 5, 6, 7" << endl;
    runner.Run(arr, size, justFiller, insertSort, printer);
*/
//////Test Equal//////
/*
    Equal CompareT;
    int a = CompareT.Compare(1, 2);
    cout << "Test 1 Expected: -1" << endl;
    cout << "Result: " << a << endl;
    int b = CompareT.Compare(2, 1);
    cout << "Test 2 Expected: 1" << endl;
    cout << "Result: " << b << endl;
    int c = CompareT.Compare(1, 1);
    cout << "Test 3 Expected: 0" << endl;
    cout << "Result: " << c << endl;
*/

    delete [] arr;

    return 0;
}

