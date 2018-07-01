#ifndef STACKH_H_INCLUDED
#define STACKH_H_INCLUDED

#include <iostream>
#include "iomanip"

using namespace std;

template <typename T>
class Stack
{
private:
    T *StackE;
    int dimention;
    int top;

public:
    Stack(int a);
    Stack(const Stack<T> &); //Copy
    ~Stack();

    void push(T);
    T pop();
    T Peek(int );
    void printStack();


    T *getStack() const;
    int getStackSize() const;
    int getTop() const;

    Stack &operator=(const Stack&);
};

template <typename T>
Stack<T>::Stack(int a)
{
    dimention = a;
    StackE = new T[dimention];
    top = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] StackE;
}

template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack)
{
    dimention = otherStack.getStackSize();
    StackE = new T[dimention];
    top = otherStack.getTop();

    for(int i = 0; i < top; i++)
        StackE[i] = otherStack.getStack()[i];
}

template <typename T>
void Stack<T>::push(T value)
{
    if (top < dimention)
    {
        StackE[top++] = value;
    }
    else
    {
        cout << "Stack is full." <<  endl;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (top > 0)
    {
        top--;
        StackE[top];
    }
    else
    {
        cout << "Stack already is empty." << endl;
    }
}

template <class T>
T Stack<T>::Peek(int n)
{
  if (n <= top)
  {
      return StackE[top - n];
  }
}

template <typename T>
void Stack<T>::printStack()
{
    for (int i = top - 1; i >= 0; i--)
        cout << "|" << setw(4) << StackE[i] << endl;
}


template <typename T>
T *Stack<T>::getStack() const
{
    return StackE;
}

template <typename T>
int Stack<T>::getStackSize() const
{
    return dimention;
}

template <typename T>
int Stack<T>::getTop() const
{
    return top;
}

template  <typename T>
Stack<T> &Stack<T>::operator=(const Stack &other)
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
#endif // STACKH_H_INCLUDED
