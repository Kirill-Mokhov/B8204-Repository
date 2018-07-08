#ifndef STACKH_H_INCLUDED
#define STACKH_H_INCLUDED

#include <iostream>
#include "iomanip"

using namespace std;

template <typename T>
class StackInterface
{
public:
    virtual void push(T) = 0;
    virtual T pop() = 0;
    virtual void printStack() = 0;

    virtual T *getStack() const = 0;
    virtual int getStackSize() const = 0;
    virtual int getTop() const = 0;

    StackInterface &operator=(const StackInterface&);
};

template <typename T>
class Stack : public StackInterface <T>
{
private:
    T *StackE;
    int dimention;
    int top;

public:
    Stack(int a)
    {
        dimention = a;
        StackE = new T[dimention];
        top = 0;
    }

    Stack(const Stack<T> & otherStack)
    {
        dimention = otherStack.getStackSize();
        StackE = new T[dimention];
        top = otherStack.getTop();

        for(int i = 0; i < top; i++)
            StackE[i] = otherStack.getStack()[i];
    }

    ~Stack()
    {
        delete [] StackE;
    }

    void push(T value) override
    {
        if (top < dimention)
        {
            StackE[top++] = value;
        }
    }

    T pop() override
    {
        if (top > 0)
        {
            top--;
            return StackE[top];
        }
    }

    void printStack() override
    {
        for (int i = top - 1; i >= 0; i--)
            cout << "|" << setw(4) << StackE[i] << endl;
    }

    T* getStack() const override
    {
        return StackE;
    }

    int getStackSize() const override
    {
        return dimention;
    }

    int getTop() const override
    {
        return top;
    }

    Stack &operator=(const Stack &other)
    {
        dimention = other.getStackSize();

        if (this->StackE != NULL)
        {
            delete [] this->StackE;
        }

        StackE = new T[dimention];
        top = other.getTop();

        for(int i = 0; i < top; i++)
            StackE[i] = other.getStack()[i];
    }
};

#endif // STACKH_H_INCLUDED
