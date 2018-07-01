#ifndef FILLER_H_INCLUDED
#define FILLER_H_INCLUDED
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

class FillerInterface
{
public:
    virtual void fill(int* v, int size) = 0;
};

class RandomFiller : public FillerInterface
{
    int top;
public:
    RandomFiller(int a) : top(a) {}

    void fill(int* v, int n) override
    {
        for(int i = 0; i < n; i++)
        {
            v[i] = rand() % top;
        }
    }
};

class JustFiller : public FillerInterface
{
    int A;
    int B;
public:
    JustFiller(int a, int b) : A(a), B(b){}

    void fill(int* v, int n) override
    {
        for(int i = 0; i < n; i++)
        {
            v[i] = i % 5 + A % B;
        }
    }
};


#endif // FILLER_H_INCLUDED
