#include <iostream>
#include <ctime>
#include <cmath>

using std::cout;
using std::endl;

class ComparatorInterface {
public:
    virtual int compare(int a, int b) = 0;
};

class ComparatorLess: public ComparatorInterface {
public:
    int compare(int a, int b) override {
        if (a < b) return 1;
        if (a > b) return -1;
        return 0;
    }
};

class ComparatorGreater: public ComparatorInterface {
public:
    int compare(int a, int b) override {
        if (a > b) return 1;
        if (a < b) return -1;
        return 0;
    }
};

class SorterInterface {
public:
    virtual void sort(int *arr, size_t size) = 0;
};

class Sorter: public SorterInterface {
protected:
    ComparatorInterface *comparator;
public:
    explicit Sorter(ComparatorInterface *comparator) : comparator(comparator) {}
};

class BubbleSorter: public Sorter {
public:
    explicit BubbleSorter(ComparatorInterface *comparator) : Sorter(comparator) {}

    void sort(int *arr, size_t size) override {

        for (size_t i = 0; i < size; ++i) {
            bool swapped = false;
            for (size_t j = 0; j < size-i-1; ++j) {
                if ( comparator->compare(arr[j], arr[j+1]) > 0 ) {
                    std::swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
};

class HeapSorter: public Sorter {
private:
    size_t heapSize;

    size_t left(size_t i) {
        return 2*i + 1;
    }

    size_t right(size_t i) {
        return 2*i + 2;
    }

    void maxHeapify(int *arr, size_t i) {

        size_t l = left(i);
        size_t r = right(i);

        size_t largest;

        if ( (l < heapSize) && (comparator->compare(arr[l], arr[i]) > 0) ) {
            largest = l;
        } else {
            largest = i;
        }

        if ( (r < heapSize) && (comparator->compare(arr[r], arr[largest]) > 0) ) {
            largest = r;
        }

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            maxHeapify(arr, largest);
        }
    }

    void buildMaxHeap(int *arr, size_t arrSize) {

        heapSize = arrSize;

        for (size_t i = static_cast<size_t>( trunc(arrSize / 2) ); (i >= 0) && (i < arrSize); i--) {
            maxHeapify(arr, i);
        }
    }

public:
    explicit HeapSorter(ComparatorInterface *comparator) : Sorter(comparator) {}

    void sort(int *arr, size_t size) override {
        buildMaxHeap(arr, size);

        for (size_t i = size - 1; i >= 1; i--) {
            std::swap(arr[0], arr[i]);
            heapSize -= 1;
            maxHeapify(arr, 0);
        }
    }
};

class FillerInterface {
public:
    virtual void fill(int *arr, size_t size) = 0;
};

class RandomFiller: public FillerInterface {
private:
    int low;
    int high;
public:
    RandomFiller(int low, int high) : low(low), high(high) {}

    void fill(int *arr, size_t size) override {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = rand() % high + low;
        }
    }
};

class StraightFiller: public FillerInterface {
public:
    void fill(int *arr, size_t size) override {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }
    }
};

class PrinterInterface {
public:
    virtual void print(int *arr, size_t size) = 0;
};

class ConsolePrinter: public PrinterInterface {
public:
    const char *delimiter;

    explicit ConsolePrinter(const char *delimiter) : delimiter(delimiter) {}

    void print(int *arr, size_t size) override {
        for (size_t i = 0; i < size - 1; ++i) {
            cout << arr[i] << delimiter;
        }
        cout << arr[size - 1] << endl;
    }
};

class Runner {
public:
    void run(SorterInterface& sorter, FillerInterface& filler, PrinterInterface& printer, int *arr, size_t size) {
        filler.fill(arr, size);
        printer.print(arr, size);
        sorter.sort(arr, size);
        printer.print(arr, size);
        cout << endl;
    }
};

int main() {

    srand(time(NULL));

    size_t size = 10;
    int *arr = new int[size];

    RandomFiller randomFiller(0, 20);
    ComparatorLess comparatorLess;
    BubbleSorter bubbleSorter(&comparatorLess);
    ConsolePrinter consolePrinter("\t");

    Runner runner;

    runner.run(bubbleSorter, randomFiller, consolePrinter, arr, size);


    ComparatorGreater comparatorGreater;
    BubbleSorter bubbleSorterGreater(&comparatorGreater);
    runner.run(bubbleSorterGreater, randomFiller, consolePrinter, arr, size);


    HeapSorter heapSorter(&comparatorGreater);
    runner.run(heapSorter, randomFiller, consolePrinter, arr, size);


    HeapSorter heapSorterLess(&comparatorLess);
    StraightFiller straightFiller;
    runner.run(heapSorterLess, straightFiller, consolePrinter, arr, size);


    delete [] arr;

    return 0;
}