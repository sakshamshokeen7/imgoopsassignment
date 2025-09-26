#include "../headers/vector.h"

template <typename T>
Vector<T>::Vector() {
    capacity = 10;
    size = 0;
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size > 0)
        size--;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    return arr[index];
}

template <typename T>
int Vector<T>::getSize() const {
    return size;
}

template <typename T>
bool Vector<T>::empty() const {
    return size == 0;
}
