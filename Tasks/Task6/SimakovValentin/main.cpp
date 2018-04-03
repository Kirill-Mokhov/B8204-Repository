#include <iostream>
#include <ctime>

using namespace std;

//####################SORT####################
class SorterInterface{
protected:
    bool increasing;
public:
    SorterInterface(bool _increasing){
        increasing = _increasing;
    }
    virtual void sort(int* v, unsigned int size) = 0;
};

class BubbleSort: public SorterInterface{
public:
    BubbleSort(bool increasing): SorterInterface(increasing){};
    void sort(int* v, unsigned int size){
        for(int i = 0; i < size; i++)
            for(int j = 0; j < i; j++)
                if(increasing ? v[i] < v[j] : v[i] > v[j]) swap(v[i], v[j]);
    }
};

class ShakerSort: public SorterInterface{
public:
    ShakerSort(bool increasing): SorterInterface(increasing){};
    void sort(int* v, unsigned int size){
        int leftMark = 1;
        int rightMark = size - 1;
        while (leftMark <= rightMark){
            for (int i = rightMark; i >= leftMark; i--)
                if (increasing ? v[i-1] > v[i] : v[i-1] < v[i]) swap(v[i-1], v[i]);
            leftMark++;

            for (int i = leftMark; i <= rightMark; i++)
                if (increasing ? v[i-1] > v[i] : v[i-1] < v[i]) swap(v[i-1], v[i]);
            rightMark--;
        }
    }
};

//####################FILL####################
class FillerInterface{
protected:
    int* resource;
public:
    virtual void inputResource(unsigned int size) = 0;
    virtual void fill(int* v, unsigned int size) = 0;

    ~FillerInterface(){
        delete[] resource;
    }
};

class FillerManual: public FillerInterface{
public:
    void inputResource(unsigned int size){
        resource = new int[size];
        for(unsigned int i = 0; i < size; i++)
            cin >> resource[i];
    }

    void fill(int* v, unsigned int size){
        for(unsigned int i = 0; i < size; i++)
            v[i] = resource[i];
    }
};

class FillerRandom: public FillerInterface{
private:
    int left, right;

public:
    void inputResource(unsigned int size){
        resource = new int[size];
        for(unsigned int i = 0; i < size; i++){
            resource[i] = rand() % right + left;
        }
    }

    FillerRandom(int l, int r){
        try{
            if(l > r) throw "Error! In FillerRandom: Invalid interval for randomize";
            left = l;
            right = r;
        } catch(const char* err){
            cout << err << endl;
            left = 0;
            right = 1;
        }
    }

    void fill(int* v, unsigned int size){
        this->inputResource(size);
        for(unsigned int i = 0; i < size; i++)
            v[i] = resource[i];
    }
};

//####################PRINT####################
class PrinterInterface{
protected:
    string delimiter = " ";

public:
    virtual void print(int* v, unsigned int size) = 0;
};

class Printer: public PrinterInterface{
public:
    Printer(string symbol){
        delimiter = symbol;
    }

    void print(int* v, unsigned int size){
        for(int i = 0; i < size - 1; i++)
            cout << v[i] << delimiter;
        cout << v[size-1] << endl;
    }
};

//####################RUN####################
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
//####################***####################

int main(){
    unsigned int size = 10;
    int* a = new int[size];

    FillerRandom fillerR(1, 100);
    Printer printer(", ");
    BubbleSort bubble(true);
    ShakerSort shaker(false);
    Runner runner;

    runner.run(fillerR, printer, bubble, a, size);
    runner.run(fillerR, printer, shaker, a, size);

    return 0;
}
