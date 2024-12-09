#pragma once

#include <cstddef>

template<typename T>
class MutableSequence {
public:
    virtual ~MutableSequence() = default;

    virtual T& operator[](size_t index) = 0;
    virtual const T& operator[](size_t index) const = 0;

    virtual size_t getSize() const = 0;

    virtual void append(const T& item) = 0;
    virtual void insert(const T& item, size_t index) = 0;
    virtual void removeAt(size_t index) = 0;
};
