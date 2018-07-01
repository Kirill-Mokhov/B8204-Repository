#include <iostream>
#include "run.h"
using namespace std;
int main()
{
    unsigned int Size = 5;
    //int* Arr = new int[Size];
    int* Arr1 = new int[Size];
    int* Arr2 = new int[Size];


    CompareTool compare1;
    CompareToolReverse compare2;
    SwapToolTEST Switch;
    StandartPrint print;
    FillerManual fill1;
    FillerRandom fill2;
    Runner runner;

    BubbleSort bubble(compare1, Switch);
    QuickSort quick(compare2, Switch);

    cout << "Bubble Sort: " << endl;
    runner.run(fill1, bubble, print, Arr1, Size);
    cout << "Quick Sort: " << endl;
    runner.run(fill2, quick, print, Arr2, Size);
	system("pause");
    return 0;
}