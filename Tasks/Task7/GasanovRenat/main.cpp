#include <iostream>
#include <string>
#include <gtest/gtest.h>
//#include <iterator>
//#include <list>

using namespace std;

template<class T>
class DequeInterface {
public:
    virtual void pushLeft(T n) = 0;

    virtual void pushRight(T n) = 0;

    virtual T* popLeft() = 0;

    virtual T* popRight() = 0;

    virtual T* Left() = 0;

    virtual T* Right() = 0;

    virtual int getSize() = 0;

    DequeInterface &operator=(DequeInterface &a);
};

template<class T>
class StaticDeque : public DequeInterface<T> {
private:
    int size = 3;
    T *storage;
    int left, right;

    void slideL() {
        int step = left / 2;
        for (int i = left + 1; i <= right - 1; i++) {
            storage[i - step] = storage[i];
        }
        left -= step;
        right -= step;
    }

    void slideR() {
        int step = (size - right + 1) / 2;
        for (int i = right - 1; i >= left + 1; i--) {
            storage[i + step] = storage[i];
        }
        left += step;
        right += step;
    }

    class iterator {
    public:
        typedef iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;

        iterator(pointer ptr) : ptr_(ptr) {}

        self_type operator++() {
            self_type i = *this;
            ptr_++;
            return i;
        }

        self_type operator++(int junk) {
            ptr_++;
            return *this;
        }

        reference operator*() { return *ptr_; }

        pointer operator->() { return ptr_; }

        bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }

        bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

    private:
        pointer ptr_;
    };

    class const_iterator {
    public:
        typedef const_iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;

        const_iterator(pointer ptr) : ptr_(ptr) {}

        self_type operator++() {
            self_type i = *this;
            ptr_++;
            return i;
        }

        self_type operator++(int junk) {
            ptr_++;
            return *this;
        }

        const reference operator*() { return *ptr_; }

        const pointer operator->() { return ptr_; }

        bool operator==(const self_type &rhs) { return ptr_ == rhs.ptr_; }

        bool operator!=(const self_type &rhs) { return ptr_ != rhs.ptr_; }

    private:
        pointer ptr_;
    };

    iterator begin() {
        return iterator(storage + 1 + left);
    }

    iterator end() {
        return iterator(storage + right);
    }

    const_iterator begin() const {
        return const_iterator(storage);
    }

    const_iterator end() const {
        int gg = 0;
        if (left == right) gg = 0;
        else gg = right - left - 1;
        return const_iterator(storage + gg);
    }

public:
    void getIterator(){
        for (StaticDeque<T>::iterator i = this->begin(); i != this->end(); i++) {
            std::cout << "|" << *i << "|" << " ";
        }
        cout << endl;
    }

    StaticDeque(int maxSize) {
        if (maxSize > 3) size = maxSize;
        left = size / 2;
        right = size / 2;
        storage = new T[size];
    }

    StaticDeque(const StaticDeque &clone) {
        size = clone.size;
        left = clone.left;
        right = clone.right;
        storage = new T[size];
        for (int i = left + 1; i <= right - 1; i++) {
            storage[i] = clone.storage[i];
        }
    }

    ~StaticDeque() {
        delete[] storage;
    }

    StaticDeque &operator=(StaticDeque &a) {
        left = 0;
        right = 0;
        int counter = 0;
        int max = a.getSize() - 1;
        int curr = a.left + 1;
        for (int i = 0; i <= max; i++) {
            counter++;
            if (counter == size + 1) break;
            pushRight(a.storage[curr + i]);
        }
        return *this;
    }

    void pushLeft(T n) {
        if (this->getSize() == size) { cout << "Deque is full!" << endl; }
        else if (this->getSize() == 0) {
            storage[left] = n;
            left--;
            right++;
        }
        else {
            if (left == 0) {
                this->slideR();
                storage[left] = n;
                left--;
            }
            else {
                storage[left] = n;
                left--;
            }
        }
    }

    void pushRight(T n) {
        if (this->getSize() == size) { cout << "Deque is full!" << endl; }
        else if (this->getSize() == 0) {
            storage[right] = n;
            right++;
            left--;
        }
        else {
            if (right == size - 1) {
                this->slideL();
                storage[right] = n;
                right++;
            }
            else {
                storage[right] = n;
                right++;
            }
        }
    }

    T* popLeft() {
        if (this->getSize() == 0) return nullptr;
        else {
            T* ptr  = &storage[left + 1];
            left++;
            if (this->getSize() == 0) {
                left = size / 2;
                right = size / 2;
            }
            return ptr;
        }
    }

    T* popRight() {
        if (this->getSize() == 0) return nullptr;
        else {
            T* ptr = &storage[right - 1];
            right--;
            if (this->getSize() == 0) {
                left = size / 2;
                right = size / 2;
            }
            return ptr;
        }
    }

    T* Left() {
        if (this->getSize() == 0) return nullptr; else return &storage[left + 1];
    }

    T* Right() {
        if (this->getSize() == 0) return nullptr; else return &storage[right - 1];
    }

    int getSize() {
        if (left == right) { return 0; }
        else return (right - left - 1);
    }
};

int main() {


    /*StaticDeque<int> d(15);
    for (int i = 1; i < 7; i++) {
        d.pushLeft(i);
        d.pushRight(i * 10);
    }
    d.getIterator();

    StaticDeque<float> test(4);
    test.pushRight(1.5);
    test.pushRight(5.5);
    test.pushLeft(7.5);
    cout<<"PRINTING FLOAT"<<endl;
    test.getIterator();

    StaticDeque<int> test22(4);
    test22.pushRight(1);
    test22.pushRight(666);
    test22.pushRight(5);
    test22.pushLeft(7);
    cout<<"PRINTING SMTH"<<endl;
    test22.getIterator();

    StaticDeque<int> LLL(14);
    LLL.pushRight(55);
    LLL.pushRight(77);
    LLL.pushRight(66);
    LLL.pushRight(88);
    LLL.pushRight(889);
    LLL.pushRight(878);
    LLL.pushLeft(777);
    StaticDeque<int> KKK(15);
    KKK = LLL;
    cout << "PRINTING"<<endl;
    KKK.getIterator();*/

    //return 0;
    return RUN_ALL_TESTS();
}