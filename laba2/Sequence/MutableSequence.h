#pragma once

#include <stdexcept>

template <typename T>
class MutableSequence
{
public:
    virtual ~MutableSequence() = default;

    virtual T& operator[](int index) = 0;
    virtual const T& operator[](int index) const = 0;

    virtual int getSize() const = 0;
    virtual void resize(int newSize) = 0;

    virtual void append(const T& item) = 0;
    virtual void insert(int index, const T& item) = 0;
    virtual void remove(int index) = 0;
};


