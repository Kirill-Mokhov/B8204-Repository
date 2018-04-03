#include <iostream>
#include <ctime>

using namespace std;

//####################COMPARE####################
class ComparatorInterface{
public:
    virtual char compare(int leftOperand, int rightOperand) = 0;
};

class ComparatorLess: public ComparatorInterface{
public:
    char compare(int leftOperand, int rightOperand){
        if(leftOperand < rightOperand) return 1;
        if(leftOperand > rightOperand) return -1;
        if(leftOperand == rightOperand) return 0;
    }
};

class ComparatorBigger: public ComparatorInterface{
public:
    char compare(int leftOperand, int rightOperand){
        if(leftOperand > rightOperand) return 1;
        if(leftOperand < rightOperand) return -1;
        if(leftOperand == rightOperand) return 0;
    }
};

class ComparatorDivisibilityBy2: public ComparatorInterface{
public:
    char compare(int leftOperand, int rightOperand){
        if(leftOperand % 2 == 0 && rightOperand % 2 != 0) return 1;
        if(leftOperand % 2 != 0 && rightOperand % 2 == 0) return -1;
        if(leftOperand % 2 == 0 && rightOperand % 2 == 0) return 0;
    }
};

//####################SORT####################
class SorterInterface{
protected:
    ComparatorInterface* comparator;
public:
    SorterInterface(ComparatorInterface& _comparator){
        comparator = &_comparator;
    }
    virtual void sort(int* v, unsigned int size) = 0;
};

class BubbleSort: public SorterInterface{
public:
    BubbleSort(ComparatorInterface& _comparator): SorterInterface(_comparator){};
    void sort(int* v, unsigned int size){
        for(int i = 0; i < size; i++)
            for(int j = 0; j < i; j++)
                if(comparator->compare(v[i], v[j]) == 1) swap(v[i], v[j]);
    }
};

class ShakerSort: public SorterInterface{
public:
    ShakerSort(ComparatorInterface& _comparator): SorterInterface(_comparator){};
    void sort(int* v, unsigned int size){
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
    ComparatorLess less;
    ComparatorBigger bigger;
    ComparatorDivisibilityBy2 divisibilityBy2;
    BubbleSort bubble(less);
    ShakerSort shaker(divisibilityBy2);
    Runner runner;

    runner.run(fillerR, printer, bubble, a, size);
    runner.run(fillerR, printer, shaker, a, size);

    return 0;
}
