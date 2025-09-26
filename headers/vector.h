#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int size;

public:
    Vector();
    ~Vector();

    void push_back(const T& value);
    void pop_back();
    T& operator[](int index);
    int getSize() const;
    bool empty() const;
};

#endif
