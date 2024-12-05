#pragma once

#include "ISorter.h"

template <typename T>
class ShellSorter : public ISorter<T>
{
public:
    void sort(MutableSequence<T>* data, std::function<bool(const T&, const T&)> compare,std::function<void()> callback = nullptr) override;
};

template <typename T>
void ShellSorter<T>::sort(MutableSequence<T>* data,std::function<bool(const T&, const T&)> compare,std::function<void()> callback)
{
    int size = data->getSize();
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; ++i)
        {
            T temp = (*data)[i];
            int j;
            for (j = i; j >= gap && compare(temp, (*data)[j - gap]); j -= gap)
            {
                (*data)[j] = (*data)[j - gap];
                if (callback)
                    callback();
            }
            (*data)[j] = temp;
            if (callback)
                callback();
        }
    }
}

