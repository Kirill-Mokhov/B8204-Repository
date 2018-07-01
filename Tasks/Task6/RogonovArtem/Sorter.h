#ifndef SORTER_H_INCLUDED
#define SORTER_H_INCLUDED
#include <iostream>
#include "Compare.h"
using namespace std;

class SortInterface
{
public:
    virtual void Sort(int* v, int n) = 0;
    //virtual void Sort(int* v, int l, int r) = 0;
};

class Sorterer : public SortInterface
{
protected:
    CompareInterface* comparator;
public:
    Sorterer(CompareInterface* a) : comparator(a) {}
};

class BubbleSort : public Sorterer
{
public:
    BubbleSort(CompareInterface* a) : Sorterer(a){}

    void Sort(int* v, int n) override
    {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (comparator->Compare(v[i], v[j]) == 1)
                    swap(v[i], v[j]);
            }
        }
    }
};

class InsertSort : public Sorterer
{
public:
    InsertSort(CompareInterface* a) : Sorterer(a){}

    void Sort(int* v, int n) override
    {
        for (int i = 1; i < n; i++)
            for(int j = i; j > 0 && comparator->Compare(v[j - 1], v[j]) == 1; j--)
            {
                swap(v[j - 1], v[j]);
            }
    }
};

/*
class QuickSort : public Sorterer
{
    void SortQ(int* v, int a, int b)
    {
        int l = a;
        int r = b - 1;
        int p = v[(l + r) / 2];

        while (l <= r)
        {
            while (comparator->Compare(v[l], p) == -1)
                l++;
            while (comparator->Compare(v[r], p) == 1)
                r++;
            if (l <= r)
            {
                swap(v[l], v[r]);
                l++;
                r--;
            }
        }
        if (a < r)
            SortQ(v, a, r);
        if (l < b)
            SortQ(v, l, b);
    }
public:
    QuickSort(CompareInterface* a) : Sorterer(a){};

    void Sort(int* v, int n) override
    {
        int q = 1;
        SortQ(v, q, n - 1);
    }
};
*/

#endif // SORTER_H_INCLUDED
