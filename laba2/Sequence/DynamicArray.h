#pragma once

#include "MutableSequence.h"
#include <stdexcept>
#include <algorithm>


template<typename T>
class DynamicArray : public MutableSequence<T> {
public:
    DynamicArray();
    explicit DynamicArray(size_t initialSize);
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray<T>& operator=(const DynamicArray<T>& other);
    ~DynamicArray();

    T& operator[](size_t index) override;
    const T& operator[](size_t index) const override;

    size_t getSize() const override;

    void append(const T& item) override;
    void insert(const T& item, size_t index) override;
    void removeAt(size_t index) override;

private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);
};


template<typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0), capacity(0) {}

template<typename T>
DynamicArray<T>::DynamicArray(size_t initialSize) : data(new T[initialSize]), size(initialSize), capacity(initialSize) {}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) : data(nullptr), size(0), capacity(0) {
    if (other.capacity > 0) {
        data = new T[other.capacity];
        size = other.size;
        capacity = other.capacity;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
        if (other.capacity > 0) {
            data = new T[other.capacity];
            size = other.size;
            capacity = other.capacity;
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range in DynamicArray");
    }
    return data[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range in DynamicArray");
    }
    return data[index];
}

template<typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}


template<typename T>
void DynamicArray<T>::append(const T& item) {
    if (size == capacity) {
        resize((capacity == 0) ? 1 : capacity * 2);
    }
    data[size++] = item;
}

template<typename T>
void DynamicArray<T>::insert(const T& item, size_t index) {
    if (index > size) {
        throw std::out_of_range("Index out of range in DynamicArray insert");
    }
    if (size == capacity) {
        resize((capacity == 0) ? 1 : capacity * 2);
    }
    for (size_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = item;
    ++size;
}

template<typename T>
void DynamicArray<T>::removeAt(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range in DynamicArray removeAt");
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template<typename T>
void DynamicArray<T>::resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    size_t elementsToCopy = (newCapacity < size) ? newCapacity : size;
    for (size_t i = 0; i < elementsToCopy; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
    if (size > capacity) {
        size = capacity;
    }
}
