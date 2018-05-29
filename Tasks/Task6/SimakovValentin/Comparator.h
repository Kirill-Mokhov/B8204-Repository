#ifndef COMPARATOR_H
#define COMPARATOR_H

class ComparatorInterface{
public:
    virtual char compare(int leftOperand, int rightOperand) = 0;
};

class ComparatorLess: public ComparatorInterface{
public:
    char compare(int leftOperand, int rightOperand) override {
        if(leftOperand < rightOperand) return 1;
        if(leftOperand > rightOperand) return -1;
        if(leftOperand == rightOperand) return 0;
    }
};

class ComparatorBigger: public ComparatorInterface{
public:
    char compare(int leftOperand, int rightOperand) override {
        if(leftOperand > rightOperand) return 1;
        if(leftOperand < rightOperand) return -1;
        if(leftOperand == rightOperand) return 0;
    }
};

class ComparatorDivisibilityBy2: public ComparatorInterface{
public:
    char compare(int leftOperand, int rightOperand) override {
        if(leftOperand % 2 == 0 && rightOperand % 2 != 0) return 1;
        if(leftOperand % 2 != 0 && rightOperand % 2 == 0) return -1;
        if(leftOperand % 2 == 0 && rightOperand % 2 == 0) return 0;
    }
};

#endif
