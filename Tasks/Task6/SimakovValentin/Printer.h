#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>

class PrinterInterface{
protected:
    std::string delimiter = " ";

public:
    virtual void print(int* v, unsigned int size) = 0;
};

class Printer: public PrinterInterface{
public:
    Printer(std::string symbol){
        delimiter = symbol;
    }

    void print(int* v, unsigned int size) override {
        for(int i = 0; i < size - 1; i++)
            std::cout << v[i] << delimiter;
        std::cout << v[size-1] << std::endl;
    }
};

#endif
