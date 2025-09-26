#include "vector.h"

template <typename T>
Vector<T>::Vector() : size(0), capacity(10) {
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity) {
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this == &other) return *this;
    delete[] arr;
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
    return *this;
}

template <typename T>
void Vector<T>::resize(int newCapacity) {
    T* newArr = new T[newCapacity];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity)
        resize(capacity * 2);
    arr[size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) size--;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");
    return arr[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");
    return arr[index];
}

template <typename T>
T& Vector<T>::get(int index) {
    return operator[](index);
}

template <typename T>
const T& Vector<T>::get(int index) const {
    return operator[](index);
}

template <typename T>
int Vector<T>::getSize() const {
    return size;
}

template <typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template <typename T>
void Vector<T>::clear() {
    size = 0;
}
