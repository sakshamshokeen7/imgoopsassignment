#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* arr;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    Vector();
    ~Vector();
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);

    void push_back(const T& value);
    void pop_back();
    void erase(int index);   

    T& operator[](int index);
    const T& operator[](int index) const;

    T& get(int index);
    const T& get(int index) const;

    int getSize() const;
    bool empty() const;
    void clear();
};

#include "vector.cpp"

#endif
