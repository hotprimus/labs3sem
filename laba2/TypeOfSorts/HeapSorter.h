#pragma once

#include "ISorter.h"

template<typename T>
class HeapSorter : public ISorter<T> {
public:
    void sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare = std::less<T>()) override;

private:
    void heapify(T* data, size_t n, size_t i, std::function<bool(const T&, const T&)> compare);
};

template<typename T>
void HeapSorter<T>::sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare) {
    if (size <= 1) return;

    for (int i = static_cast<int>(size / 2 - 1); i >= 0; --i) {
        heapify(data, size, static_cast<size_t>(i), compare);
    }

    for (int i = static_cast<int>(size - 1); i >= 0; --i) {
        std::swap(data[0], data[i]); 
        heapify(data, static_cast<size_t>(i), 0, compare); 
    }
}

template<typename T>
void HeapSorter<T>::heapify(T* data, size_t n, size_t i, std::function<bool(const T&, const T&)> compare) {
    size_t largest = i;
    size_t left = 2 * i + 1; 
    size_t right = 2 * i + 2; 
    if (left < n && compare(data[largest], data[left])) {
        largest = left;
    }

    if (right < n && compare(data[largest], data[right])) {
        largest = right;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest, compare);
    }
}
