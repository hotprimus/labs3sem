#pragma once

#include "ISorter.h"


template<typename T>
class QuickSorter : public ISorter<T> {
public:
    void sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare = std::less<T>()) override;

private:
    void quickSort(T* data, int low, int high, std::function<bool(const T&, const T&)> compare);
    int partition(T* data, int low, int high, std::function<bool(const T&, const T&)> compare);
};


template<typename T>
void QuickSorter<T>::sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare) {
    if (size > 1) {
        quickSort(data, 0, static_cast<int>(size - 1), compare);
    }
}


template<typename T>
void QuickSorter<T>::quickSort(T* data, int low, int high, std::function<bool(const T&, const T&)> compare) {
    if (low < high) {
        int pi = partition(data, low, high, compare);
        quickSort(data, low, pi - 1, compare);
        quickSort(data, pi + 1, high, compare);
    }
}


template<typename T>
int QuickSorter<T>::partition(T* data, int low, int high, std::function<bool(const T&, const T&)> compare) {
    T pivot = data[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (compare(data[j], pivot)) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}
