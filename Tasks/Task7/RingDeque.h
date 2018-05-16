// Created by User on 04.04.2018.
//

#ifndef LAB2_RINGDEQUE_H
#define LAB2_RINGDEQUE_H

#include <stddef.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
/*#include <iterator>
template <class T>
T<T> DequeIterator;
template <class T>
T<T> :: iterator = DequeIterator.begin();

class DequeIterator {

};



template <class T>
class DequeInterface {
public:
    int PushBack(T a); //запись слева
    int PushFront(T a);//запись справа
    int PopBack();   //получение элемента слева
    int PopFront();  //получение элемента справа
    T* PeekBack();  //чтение слева
    T* PeekFront(); //чтение справа
    int getLength();
};*/

/*
 * TODO
 *
 * */
template <class T>
class RingDeque {
private:
    string name;
    int dimension = 4;
    int leftEnter, rightEnter;
    T* arr;
public:
    RingDeque(int dim, string n);
    RingDeque(const RingDeque<T> &a); //конструктор копирования
    ~RingDeque();
    int PushBack(T a); //запись слева
    int PushFront(T a);//запись справа
    int PopBack();   //получение элемента слева
    int PopFront();  //получение элемента справа
    T PeekBack();  //чтение слева
    T PeekFront(); //чтение справа
    void print();   // печать
    int getLength();// получение длины дека (количества элементов добавленных в дек)
    string getName();
    RingDeque&  operator=(RingDeque&);
};



#endif //LAB2_RINGDEQUE_H
