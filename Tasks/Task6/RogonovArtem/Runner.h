#ifndef RUNNER_H_INCLUDED
#define RUNNER_H_INCLUDED
#include <iostream>
#include "Sorter.h"
#include "Filler.h"
#include "Printer.h"

using namespace std;

class Runner
{
public:
    void Run(int* v, int n, FillerInterface& filler, SortInterface& sorter, PrinterInterface& printer)
    {
        filler.fill(v, n);
        cout << "Incoming:" << endl;
        printer.Print(v, n);
        sorter.Sort(v, n);
        cout << "Out:" << endl;
        printer.Print(v, n);
        cout << endl;
    }
};

#endif // RUNNER_H_INCLUDED
