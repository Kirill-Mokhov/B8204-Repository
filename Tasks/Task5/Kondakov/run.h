#ifndef SHAKERSORTOOP_RUN_H
#define SHAKERSORTOOP_RUN_H

#include "fill.h"
#include "print.h"
#include "sort.h"

class Runner{
public:
    void run(FillerInterface& filler, SortInterface& sortUtil, PrintInterface& printer,  int* Arr, int Size){
        filler.fill(Arr, Size);
        cout << "Array before sorting:" << endl;
        printer.print(Arr, Size);
        sortUtil.Sort(Arr, Size);
        cout << "Array after sorting:" << endl;
        printer.print(Arr, Size);
        cout << endl;
    };
};

#endif //SHAKERSORTOOP_RUN_H
