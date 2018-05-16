//
// Created by User on 04.04.2018.
//

#include "RingDeque.h"

template <class T> // Конструктор
RingDeque<T>::RingDeque(int dim, string n)
{
    if (dim > 3) dimension = dim + 1;
    name = n;
    leftEnter = dimension / 2;
    rightEnter = dimension / 2 - 1;
    arr = new T[dimension];
}

template  <class T> //Конструктор копирования
RingDeque<T>::RingDeque(const RingDeque &a)
{
    name = a.name + ".copy";
    dimension = a.dimension;
    leftEnter = a.leftEnter;
    rightEnter = a.rightEnter;
    arr = new T[dimension];
    for (int i = 0; i <= dimension - 1; i++)
    {
        if (a.arr[i] != NULL) arr[i] = a.arr[i];
    }
}

template <class T> // Деструктор
RingDeque<T>::~RingDeque() {
    delete arr;
}

template <class T> // Печать
void RingDeque<T>::print()
{
    if (getLength() != 0)
    {
        int i = leftEnter;
        cout << name << " print:" << endl;
            for (i; i != rightEnter; i++)
            {
                if (i == dimension) i = 0;
                cout << arr[i] << " ";
            }

            cout << arr[i] << endl;
    }
    else
    {
        cout << "Ring deque ";
        cout << name;
        cout << " is empty." << endl;
    }
}

template <class T> // Длина
int RingDeque<T>::getLength() {
    if ((1 == leftEnter - rightEnter) || (rightEnter - leftEnter == dimension - 1)) return 0;
    else if (leftEnter == rightEnter) return 1;
    else if (rightEnter > leftEnter) return rightEnter - leftEnter + 1;
    else if (leftEnter > rightEnter) return dimension - (leftEnter - rightEnter) + 1;
}

template <class T> // Чтение слева
T RingDeque<T>::PeekFront()
{
    return arr[leftEnter];
}

template <class T> // Чтение справа
T RingDeque<T>::PeekBack()
{
    return arr[rightEnter];
}

template <class T>
int RingDeque<T>::PopFront()
{
    if (getLength() == 0) return -315;
    else 
    {
        if (leftEnter == dimension - 1) leftEnter = 0;
        else leftEnter++;
        return 0;
    }
}

template <class T>
int RingDeque<T>::PopBack()
{
    if (getLength() == 0) return -315;
    else 
    {
        if (rightEnter == 0) rightEnter = dimension - 1;
        else rightEnter--;
        return 0;
    }
}

template <class T>
int RingDeque<T>::PushFront(T a)
{
    if (getLength() == dimension - 1) return -301; // Дек заполнен, элемент не добавлен.
    else if (leftEnter == 0) leftEnter = dimension - 1;
    else leftEnter--;
    arr[leftEnter] = a;
    return 0;
}

template <class T>
int RingDeque<T>::PushBack(T a)
{
    if (getLength() == dimension - 1) return -301; // Дек заполнен, элемент не добавлен.
    else if (rightEnter == dimension - 1) rightEnter = 0;
    else rightEnter++;
    arr[rightEnter] = a;
    return 0;
}

template  <class T>
RingDeque<T>& RingDeque<T>::operator=( RingDeque& a) {
    name = name + " -> " + a.name;
    leftEnter = dimension / 2;
    rightEnter = (dimension / 2) - 1;
    int k = a.leftEnter;
    for (leftEnter; (k != a.rightEnter) && (getLength() != dimension - 1); k++)
    {
        if (k == a.dimension) k = 0;
        PushBack(a.arr[k]);
        /*  if (leftEnter == 0) leftEnter = dimension - 1;
          else leftEnter--;
          arr[leftEnter] = a.arr[k];*/
    }
    PushBack(a.arr[k]);
}

template <class T>
string RingDeque<T>::getName() {
    return name;
}
