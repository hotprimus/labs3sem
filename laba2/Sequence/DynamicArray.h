#pragma once

#include "MutableSequence.h"

template <typename T>
class DynamicArray : public MutableSequence<T>
{
public:
    DynamicArray();
    explicit DynamicArray(int size);
    DynamicArray(const DynamicArray<T>& other);
    ~DynamicArray() override;

    T& operator[](int index) override;
    const T& operator[](int index) const override;

    int getSize() const override;
    void resize(int newSize) override;

    void append(const T& item) override;
    void insert(int index, const T& item) override;
    void remove(int index) override;

private:
    T* data;
    int size;
    int capacity;

    void ensureCapacity(int minCapacity);
};

template <typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0), capacity(0)
{
}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity) : size(0), capacity(capacity)
{
    if (capacity < 0)
        throw std::out_of_range("Capacity cannot be negative");

    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
    : size(other.size), capacity(other.capacity)
{
    data = new T[capacity];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
    data = nullptr;
}

template <typename T>
T& DynamicArray<T>::operator[](int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
int DynamicArray<T>::getSize() const
{
    return size;
}

template <typename T>
void DynamicArray<T>::resize(int newSize)
{
    if (newSize < 0)
        throw std::out_of_range("New size cannot be negative");

    ensureCapacity(newSize);
    if (newSize > size)
    {
        for (int i = size; i < newSize; ++i)
            data[i] = T();
    }
    size = newSize;
}

template <typename T>
void DynamicArray<T>::append(const T& item)
{
    ensureCapacity(size + 1);
    data[size++] = item;
}

template <typename T>
void DynamicArray<T>::insert(int index, const T& item)
{
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of bounds");

    ensureCapacity(size + 1);
    for (int i = size; i > index; --i)
        data[i] = data[i - 1];

    data[index] = item;
    ++size;
}

template <typename T>
void DynamicArray<T>::remove(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");

    for (int i = index; i < size - 1; ++i)
        data[i] = data[i + 1];

    --size;
}

template <typename T>
void DynamicArray<T>::ensureCapacity(int minCapacity)
{
    if (capacity >= minCapacity)
        return;

    int newCapacity = capacity == 0 ? 1 : capacity * 2;
    while (newCapacity < minCapacity)
        newCapacity *= 2;

    T* newData = new T[newCapacity];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCapacity;
}

