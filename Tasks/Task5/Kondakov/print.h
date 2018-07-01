#ifndef SHAKERSORTOOP_PRINT_H
#define SHAKERSORTOOP_PRINT_H

#include <iostream>

class PrintInterface{
public:
    virtual void print(int* Arr, unsigned int Size) = 0;
};

class StandartPrint: public PrintInterface{
public:
    void print(int* Arr, unsigned int Size) override {
        for(int i = 0; i < Size; i++)
            cout << Arr[i] << "|";
        cout << endl;
    }
};


#endif //SHAKERSORTOOP_PRINT_H
