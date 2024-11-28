#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <cstddef>


template <typename T>
struct UniquePtrControl {
    T* ptr;

    explicit UniquePtrControl(T* p = nullptr) : ptr(p) {}
    ~UniquePtrControl() { delete ptr; }
};


template <typename T>
class unique_ptr {
private:
    T* ptr;

public:

    constexpr unique_ptr() noexcept : ptr(nullptr) {}


    explicit unique_ptr(T* p) noexcept : ptr(p) {}


    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }


    ~unique_ptr() {
        delete ptr;
    }


    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;


    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }


    T& operator*() const { return *ptr; }
    T* operator->() const noexcept { return ptr; }


    T* get() const noexcept { return ptr; }


    T* release() noexcept {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) noexcept {
        delete ptr;
        ptr = p;
    }

    void swap(unique_ptr& other) noexcept {
        std::swap(ptr, other.ptr);
    }

    explicit operator bool() const noexcept { 
        return ptr != nullptr; 
    }
};

#endif // UNIQUE_PTR_H
