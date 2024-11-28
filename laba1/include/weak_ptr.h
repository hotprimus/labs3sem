#pragma once 

#include <cstddef>
#include <atomic>
#include "shared_ptr.h"
#include "control_block.h"

// Предварительное объявление shared_ptr для избежания циклических зависимостей
   
template <typename T>
class shared_ptr;



template <typename T>
class weak_ptr {
private:
    ControlBlock<T>* control;

public:
    // Конструктор по умолчанию
    constexpr weak_ptr() noexcept : control(nullptr) {}

    // Конструктор из shared_ptr
    weak_ptr(const shared_ptr<T>& sp) noexcept : control(sp.control) {
        if (control) {
            control->weak_count.fetch_add(1, std::memory_order_relaxed);
        }
    }

    // Копирующий конструктор
    weak_ptr(const weak_ptr& other) noexcept : control(other.control) {
        if (control) {
            control->weak_count.fetch_add(1, std::memory_order_relaxed);
        }
    }

    // Конструктор перемещения
    weak_ptr(weak_ptr&& other) noexcept : control(other.control) {
        other.control = nullptr;
    }

    // Оператор копирующего присваивания
    weak_ptr& operator=(const weak_ptr& other) noexcept {
        if (this != &other) {
            // Уменьшаем старый счетчик
            if (control) {
                if (control->weak_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
                    if (control->shared_count.load(std::memory_order_acquire) == 0) {
                        delete control;
                    }
                }
            }

            // Копируем новый контрольный блок и увеличиваем счетчик
            control = other.control;
            if (control) {
                control->weak_count.fetch_add(1, std::memory_order_relaxed);
            }
        }
        return *this;
    }

    // Оператор перемещающего присваивания
    weak_ptr& operator=(weak_ptr&& other) noexcept {
        if (this != &other) {
            // Уменьшаем старый счетчик
            if (control) {
                if (control->weak_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
                    if (control->shared_count.load(std::memory_order_acquire) == 0) {
                        delete control;
                    }
                }
            }

            // Переносим контрольный блок
            control = other.control;
            other.control = nullptr;
        }
        return *this; // Исправлено с &this на *this
    }

    // Деструктор
    ~weak_ptr() {
        if (control) {
            if (control->weak_count.fetch_sub(1, std::memory_order_acq_rel) == 1) {
                // Если нет shared_ptr, удаляем контрольный блок
                if (control->shared_count.load(std::memory_order_acquire) == 0) {
                    delete control;
                }
            }
            control = nullptr;
        }
    }

    // Функция для проверки, существует ли управляемый объект
    bool expired() const noexcept {
        return !control || control->shared_count.load(std::memory_order_acquire) == 0;
    }

    // Функция для получения shared_ptr из weak_ptr
    shared_ptr<T> lock() const noexcept {
        if (expired()) {
            return shared_ptr<T>();
        }
        return shared_ptr<T>(*this);
    }

    // Метод получения количества shared_ptr
    size_t use_count() const noexcept { 
        return control ? control->shared_count.load(std::memory_order_relaxed) : 0; 
    }

    // Проверка, содержит ли weak_ptr объект
    explicit operator bool() const noexcept { 
        return use_count() > 0; 
    }

    // Дружелюбная связь с shared_ptr
    friend class shared_ptr<T>;
};

 // namespace MySmartPtrs
