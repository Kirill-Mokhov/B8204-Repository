#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include "Comparator.h"

using std::swap;

class SorterInterface{
public:
    virtual void sort(int* v, unsigned int size) = 0;
};

class Sorter: public SorterInterface{
protected:
    ComparatorInterface* comparator;

public:
    Sorter(ComparatorInterface& _comparator){
        comparator = &_comparator;
    }
};

class BubbleSort: public Sorter{
public:
    BubbleSort(ComparatorInterface& _comparator): Sorter(_comparator){};
    void sort(int* v, unsigned int size) override {
        for(int i = 0; i < size; i++)
            for(int j = 0; j < i; j++)
                if(comparator->compare(v[i], v[j]) == 1) swap(v[i], v[j]);
    }
};

class ShakerSort: public Sorter{
public:
    ShakerSort(ComparatorInterface& _comparator): Sorter(_comparator){};
    void sort(int* v, unsigned int size) override {
        int leftMark = 1;
        int rightMark = size - 1;
        while (leftMark <= rightMark){
            for (int i = rightMark; i >= leftMark; i--)
                if (comparator->compare(v[i], v[i-1]) == 1) swap(v[i-1], v[i]);
            leftMark++;

            for (int i = leftMark; i <= rightMark; i++)
                if (comparator->compare(v[i], v[i-1]) == 1) swap(v[i-1], v[i]);
            rightMark--;
        }
    }
};
#endif
