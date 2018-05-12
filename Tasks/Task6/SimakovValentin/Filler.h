#ifndef FILLER_H
#define FILLER_H

#include <ctime>
#include <iostream>

using namespace std;

class FillerInterface{
protected:
    int* resource{};
public:
    virtual void inputResource(unsigned int size) = 0;
    virtual void fill(int* v, unsigned int size) = 0;

    ~FillerInterface(){
        delete[] resource;
    }
};

class FillerManual: public FillerInterface{
public:
    void inputResource(unsigned int size) override {
        resource = new int[size];
        for(unsigned int i = 0; i < size; i++)
            cin >> resource[i];
    }

    void fill(int* v, unsigned int size) override {
        for(unsigned int i = 0; i < size; i++)
            v[i] = resource[i];
    }
};

class FillerRandom: public FillerInterface{
private:
    int left, right;

    void inputResource(unsigned int size) override {
        resource = new int[size];
        for(unsigned int i = 0; i < size; i++){
            resource[i] = rand() % right + left;
        }
    }

public:
    FillerRandom(int l, int r){
        if(l > r) throw invalid_argument("Illegal range for random");
        left = l;
        right = r;
    }

    void fill(int* v, unsigned int size) override {
        this->inputResource(size);
        for(unsigned int i = 0; i < size; i++)
            v[i] = resource[i];
    }
};

#endif
