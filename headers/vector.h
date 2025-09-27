#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;
    std::size_t capacity;
    std::size_t length;

    void grow() {
        std::size_t newCap = capacity == 0 ? 4 : capacity * 2;
        T* newData = new T[newCap];
        for (std::size_t i = 0; i < length; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    Vector(): data(nullptr), capacity(0), length(0) {}
    ~Vector(){ delete[] data; }

    void push_back(const T& item) {
        if (length >= capacity) grow();
        data[length++] = item;
    }

    T& get(std::size_t idx) {
        if (idx >= length) 
            throw std::out_of_range("index"); 
            return data[idx];
     }
    const T& get(std::size_t idx) const { 
        if (idx >= length) 
        throw std::out_of_range("index"); 
        return data[idx]; 
    }

    std::size_t getSize() const { return length; }
    bool empty() const { return length == 0; }
    bool isEmpty() const { return empty(); }

    T& operator[](std::size_t idx){ return get(idx); }
    void erase(std::size_t idx) { if (idx >= length) return; for (std::size_t i = idx; i + 1 < length; ++i) data[i] = data[i+1]; --length; }
};

#endif // VECTOR_H
