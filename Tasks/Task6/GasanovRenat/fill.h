#ifndef SHAKERSORTOOP_FILL_H
#define SHAKERSORTOOP_FILL_H

#include <ctime>
#include <iostream>

using namespace std;

class FillerInterface{
protected:
    int* resource{};
public:
    virtual void inputResource(unsigned int Size) = 0;
    virtual void fill(int* Arr, unsigned int Size) = 0;

    ~FillerInterface(){
        delete[] resource;
    }
};

class FillerManual: public FillerInterface{
public:
    void inputResource(unsigned int Size) override {
        resource = new int[Size];
        for(unsigned int i = 0; i < Size; i++)
            cin >> resource[i];
    }

    void fill(int* Arr, unsigned int Size) override {
        cout << "Manual filling. Please enter "<<Size<< " array elements below: "<<endl;
        this->inputResource(Size);//??
        for(unsigned int i = 0; i < Size; i++)
            Arr[i] = resource[i];
    }
};

class FillerRandom: public FillerInterface{
private:
    int left, right;

    void inputResource(unsigned int Size) override {
        resource = new int[Size];
        for(unsigned int i = 0; i < Size; i++){
            resource[i] = rand() % right + left;
        }
    }

public:
    FillerRandom(){
        left = 1;
        right = 1000;
    }

    void fill(int* Arr, unsigned int Size) override {
        this->inputResource(Size);
        for(unsigned int i = 0; i < Size; i++)
            Arr[i] = resource[i];
    }
};

#endif //SHAKERSORTOOP_FILL_H
