#ifndef PRINTER_H_INCLUDED
#define PRINTER_H_INCLUDED
#include <iostream>
using namespace std;

class PrinterInterface
{
public:
    virtual void Print(int* v, int n) = 0;
};

class Printer : public PrinterInterface
{
    char delimiter;

public:
    Printer(char d = ' ')
    {
        delimiter = d;
    }

    void Print(int* v, int n) override
    {
        for(int i = 0; i < n; i++)
        {
            cout << v[i] << delimiter;
        }
        cout << endl;
    }
};


#endif // PRINTER_H_INCLUDED
