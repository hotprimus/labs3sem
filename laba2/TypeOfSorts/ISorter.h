#pragma once

#include <functional>
#include "../Sequence/MutableSequence.h"

template <typename T>
class ISorter
{
public:
    virtual void sort(MutableSequence<T>* data,std::function<bool(const T&, const T&)> compare,std::function<void()> callback = nullptr) = 0;
    virtual ~ISorter() = default;
};

