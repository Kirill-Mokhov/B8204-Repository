#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
#include <iostream>
using namespace std;

class CompareInterface
{
public:
    virtual int Compare(int a, int b) = 0;
};

class Equal : public CompareInterface
{
public:
    int Compare(int a, int b) override
    {
        if (a < b) return -1;
        if (a > b) return 1;
        if (a == b) return 0;
    }
};

#endif // COMPARE_H_INCLUDED
