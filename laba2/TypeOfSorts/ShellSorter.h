#pragma once

#include "ISorter.h"


template<typename T>
class ShellSorter : public ISorter<T> {
public:
    void sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare = std::less<T>()) override;
};


template<typename T>
void ShellSorter<T>::sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare) {
    for (size_t gap = size / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < size; ++i) {
            T temp = data[i];
            size_t j = i;
            while (j >= gap && compare(temp, data[j - gap])) {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }
}
