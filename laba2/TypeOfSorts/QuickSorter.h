#pragma once 

#include "ISorter.h"

template <typename T>
class QuickSorter : public ISorter<T>
{
public:
    void sort(MutableSequence<T>* data,std::function<bool(const T&, const T&)> compare,std::function<void()> callback = nullptr) override;

private:
    void quickSort(MutableSequence<T>* data, int low, int high,std::function<bool(const T&, const T&)> compare,std::function<void()> callback);
    int partition(MutableSequence<T>* data, int low, int high,std::function<bool(const T&, const T&)> compare,std::function<void()> callback);
};

template <typename T>
void QuickSorter<T>::sort(MutableSequence<T>* data,std::function<bool(const T&, const T&)> compare,std::function<void()> callback)
{
    if (data->getSize() > 1)
        quickSort(data, 0, data->getSize() - 1, compare, callback);
}

template <typename T>
void QuickSorter<T>::quickSort(MutableSequence<T>* data, int low, int high,std::function<bool(const T&, const T&)> compare,std::function<void()> callback)
{
    if (low < high)
    {
        int pi = partition(data, low, high, compare, callback);
        quickSort(data, low, pi - 1, compare, callback);
        quickSort(data, pi + 1, high, compare, callback);
    }
}

template <typename T>
int QuickSorter<T>::partition(MutableSequence<T>* data, int low, int high,std::function<bool(const T&, const T&)> compare,std::function<void()> callback)
{
    T pivot = (*data)[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (compare((*data)[j], pivot))
        {
            ++i;
            std::swap((*data)[i], (*data)[j]);
            if (callback)
                callback();
        }
    }
    std::swap((*data)[i + 1], (*data)[high]);
    if (callback)
        callback();
    return i + 1;
}

