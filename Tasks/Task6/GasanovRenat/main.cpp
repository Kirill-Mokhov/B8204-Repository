#include <iostream>
#include "run.h"
#include <gtest/gtest.h>

using namespace std;
int main()
{
    /*unsigned int Size = 5;
    int* Arr = new int[Size];
    int* Arr1 = new int[Size];
    int* Arr2 = new int[Size];


    CompareTool compare1;
    CompareToolReverse compare2;
    SwapToolTEST swapXXX;
    StandartPrinter printer1;
    PointersPrinter printer2;
    FillerManual fill1;
    FillerRandom fill2;
    Runner runner;

    ShakerSort shaker(compare1, swapXXX);
    BubbleSort bubble(compare2, swapXXX);
    QuickSort quick(compare1, swapXXX);

    cout << "Shaker Sort: " << endl;
    runner.run(fill2, shaker, printer1, Arr, Size);
    cout << "Bubble Sort: " << endl;
    runner.run(fill1, bubble, printer2, Arr1, Size);
    cout << "Quick Sort: " << endl;
    runner.run(fill2, quick, printer1, Arr2, Size);

    return 0;*/
    return RUN_ALL_TESTS();
}