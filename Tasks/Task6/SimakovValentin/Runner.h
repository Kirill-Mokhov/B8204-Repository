#ifndef RUNNER_H
#define RUNNER_H

#include "Filler.h"
#include "Printer.h"
#include "Sorter.h"

class Runner{
public:
    void run(FillerInterface& filler, PrinterInterface& printer, SorterInterface& sorter, int* v, int size){
        filler.fill(v, size);
        cout << "Array before sorting:" << endl;
        printer.print(v, size);
        sorter.sort(v, size);
        cout << "Array after sorting:" << endl;
        printer.print(v, size);
        cout << endl;
    };
};

#endif
