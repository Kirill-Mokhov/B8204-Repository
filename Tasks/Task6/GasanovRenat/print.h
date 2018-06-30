#ifndef SHAKERSORTOOP_PRINT_H
#define SHAKERSORTOOP_PRINT_H

#include <iostream>
using namespace std;

class PrinterInterface{
public:
    virtual void print(int* Arr, unsigned int Size) = 0;
};

class StandartPrinter: public PrinterInterface{
public:
    void print(int* Arr, unsigned int Size) override {
        for(int i = 0; i < Size; i++)
            cout << Arr[i] << " ";
        cout << endl;
    }
};

class PointersPrinter: public PrinterInterface{
public:
    void print(int* Arr, unsigned int Size) override {
        for(int i = 0; i < Size-1; i++)
            cout << Arr[i] << " -> ";
        cout << Arr[Size-1] << endl;
    }
};

#endif //SHAKERSORTOOP_PRINT_H
