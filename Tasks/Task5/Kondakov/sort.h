#ifndef SHAKERSORTOOP_SORT_H
#define SHAKERSORTOOP_SORT_H

#include <iostream>
#include "compare.h"
#include "swap.h"

class SortInterface{
public:
    virtual void Sort(int *Arr, unsigned int Size) = 0;
};

class SortTool: public SortInterface{
protected:
    CompareInterface* compareTool;
    SwapInterface* swapTool;
public:
    SortTool(CompareInterface& _compareTool, SwapInterface& _swapTool){
        compareTool = &_compareTool;
        swapTool = &_swapTool;
    };
};

class QuickSort: public SortTool{
public:
    QuickSort(CompareInterface& _compareTool, SwapInterface& _swapTool): SortTool(_compareTool, _swapTool){};
    void Sort(int *Arr, unsigned int Size) {
        int start = 0;
        int end = Size - 1;
        int mid = Arr[Size / 2];
        do {
            while(Arr[start] < mid) { start++; }
            while(Arr[end] > mid) { end--; }
            if (start <= end) {
                swapTool->Swap(Arr[start], Arr[end]);
                start++; end--;
            }
        } while (start <= end);
        if (end > 0) { Sort(Arr, end + 1); }
        if (start < Size) { Sort(Arr + start, Size - start); }
    }
};

class BubbleSort: public SortTool{
public:
    BubbleSort(CompareInterface& _compareTool, SwapInterface& _swapTool): SortTool(_compareTool, _swapTool){};
    void Sort(int *Arr, unsigned int Size) {
        int j, i;
        for (i = 0; i < Size - 1; i++) {
            for (j = 0; j < Size - i - 1; j++) {
                if (compareTool->Compare(Arr[j+1], Arr[j]) == 1) swapTool->Swap(Arr[j+1], Arr[j]);
            }
        }
    }
};

#endif //
