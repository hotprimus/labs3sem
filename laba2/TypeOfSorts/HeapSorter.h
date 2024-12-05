#pragma once

#include "ISorter.h"

template <typename T>
class HeapSorter : public ISorter<T>
{
public:
    void sort(MutableSequence<T>* data,std::function<bool(const T&, const T&)> compare,std::function<void()> callback = nullptr) override;

private:
    void heapify(MutableSequence<T>* data, int size, int root,std::function<bool(const T&, const T&)> compare,std::function<void()> callback);
};

template <typename T>
void HeapSorter<T>::sort(MutableSequence<T>* data,std::function<bool(const T&, const T&)> compare,std::function<void()> callback)
{
    int size = data->getSize();

    // Build heap
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(data, size, i, compare, callback);

    // Extract elements from heap
    for (int i = size - 1; i >= 0; --i)
    {
        std::swap((*data)[0], (*data)[i]);
        if (callback)
            callback();
        heapify(data, i, 0, compare, callback);
    }
}

template <typename T>
void HeapSorter<T>::heapify(MutableSequence<T>* data, int size, int root,std::function<bool(const T&, const T&)> compare,std::function<void()> callback)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && compare((*data)[largest], (*data)[left]))
        largest = left;
    if (right < size && compare((*data)[largest], (*data)[right]))
        largest = right;

    if (largest != root)
    {
        std::swap((*data)[root], (*data)[largest]);
        if (callback)
            callback();
        heapify(data, size, largest, compare, callback);
    }
}


