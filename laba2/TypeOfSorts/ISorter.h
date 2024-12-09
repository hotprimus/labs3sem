#pragma once

#include <functional>
#include <cstddef>

template<typename T>
class ISorter {
public:
    virtual ~ISorter() = default;

   virtual void sort(T* data, size_t size, std::function<bool(const T&, const T&)> compare = std::less<T>()) = 0;
};
