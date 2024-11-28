#include <iostream>
#include "shared_ptr.h"
#include "weak_ptr.h"
#include "unique_ptr.h"

// Структура для тестирования
struct Test {
    int value;
    Test(int v) : value(v) { std::cout << "Test(" << value << ") создан.\n"; }
    ~Test() { std::cout << "Test(" << value << ") уничтожен.\n"; }
};

// Макросы для упрощения тестов
#define ASSERT_TRUE(condition, message) \
    if (!(condition)) { \
        std::cerr << "Assertion failed: " << message << "\n"; \
        return; \
    }

#define ASSERT_FALSE(condition, message) \
    if (condition) { \
        std::cerr << "Assertion failed: " << message << "\n"; \
        return; \
    }

#define ASSERT_EQ(val1, val2, message) \
    if ((val1) != (val2)) { \
        std::cerr << "Assertion failed: " << message << " (" << val1 << " != " << val2 << ")\n"; \
        return; \
    }

// Тестирование unique_ptr
void test_unique_ptr() {
    std::cout << "=== Тест unique_ptr ===\n";

    // Создание unique_ptr
    unique_ptr<Test> up1(new Test(1));
    ASSERT_TRUE(up1, "up1 должно указывать на объект");
    ASSERT_EQ(up1->value, 1, "Значение объекта должно быть 1");

    // Перемещение unique_ptr
    unique_ptr<Test> up2 = std::move(up1);
    ASSERT_FALSE(up1, "up1 должно быть пустым после перемещения");
    ASSERT_TRUE(up2, "up2 должно указывать на объект после перемещения");
    ASSERT_EQ(up2->value, 1, "Значение объекта должно быть 1 в up2");

    // Сброс unique_ptr
    up2.reset();
    ASSERT_FALSE(up2, "up2 должно быть пустым после сброса");

    // Освобождение уникального указателя
    unique_ptr<Test> up3(new Test(3));
    Test* rawPtr = up3.release();
    ASSERT_FALSE(up3, "up3 должно быть пустым после release");
    ASSERT_EQ(rawPtr->value, 3, "Значение объекта после release должно быть 3");
    delete rawPtr; // Необходимо вручную удалить объект

    std::cout << "=== Тест unique_ptr завершен ===\n\n";
}

// Тестирование shared_ptr
void test_shared_ptr() {
    std::cout << "=== Тест shared_ptr ===\n";

    // Создание shared_ptr
    shared_ptr<Test> sp1(new Test(10));
    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1");

    // Копирование shared_ptr
    {
        shared_ptr<Test> sp2 = sp1;
        ASSERT_EQ(sp1.use_count(), 2, "sp1 use_count должно быть 2 после копирования sp2");
        ASSERT_EQ(sp2.use_count(), 2, "sp2 use_count должно быть 2 после копирования");
        ASSERT_EQ(sp2->value, 10, "Значение объекта должно быть 10 в sp2");
    }

    // После выхода из блока sp2 уничтожается
    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1 после уничтожения sp2");

    // Сброс shared_ptr
    sp1.reset();
    ASSERT_EQ(sp1.use_count(), 0, "sp1 use_count должно быть 0 после сброса");

    std::cout << "=== Тест shared_ptr завершен ===\n\n";
}

// Тестирование weak_ptr
void test_weak_ptr() {
    std::cout << "=== Тест weak_ptr ===\n";

    shared_ptr<Test> sp1(new Test(20));
    weak_ptr<Test> wp1 = sp1;
    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1");
    ASSERT_EQ(wp1.use_count(), 1, "wp1 use_count должно быть 1");

    // Захват объекта через weak_ptr
    {
        shared_ptr<Test> sp2 = wp1.lock();
        ASSERT_TRUE(sp2, "sp2 должно указывать на объект");
        ASSERT_EQ(sp2->value, 20, "Значение объекта должно быть 20 в sp2");
        ASSERT_EQ(sp1.use_count(), 2, "sp1 use_count должно быть 2 во время существования sp2");
        ASSERT_EQ(sp2.use_count(), 2, "sp2 use_count должно быть 2");
    }

    // После выхода из блока sp2 уменьшается use_count
    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1 после уничтожения sp2");

    // Сброс sp1, объект должен быть уничтожен
    sp1.reset();
    ASSERT_EQ(sp1.use_count(), 0, "sp1 use_count должно быть 0 после сброса");
    ASSERT_TRUE(wp1.expired(), "wp1 должно указывать на истекший объект");

    // Попытка захватить объект через weak_ptr после уничтожения
    shared_ptr<Test> sp3 = wp1.lock();
    ASSERT_FALSE(sp3, "sp3 должно быть пустым, так как объект уничтожен");

    std::cout << "=== Тест weak_ptr завершен ===\n\n";
}

// Дополнительные тесты для проверки работы swap, self-assignment и других функций

// Тестирование swap для shared_ptr
void test_shared_ptr_swap() {
    std::cout << "=== Тест shared_ptr::swap ===\n";

    shared_ptr<Test> sp1(new Test(30));
    shared_ptr<Test> sp2(new Test(40));
    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1");
    ASSERT_EQ(sp2.use_count(), 1, "sp2 use_count должно быть 1");

    std::swap(sp1, sp2);
    ASSERT_EQ(sp1->value, 40, "После swap sp1 должно указывать на Test с value 40");
    ASSERT_EQ(sp2->value, 30, "После swap sp2 должно указывать на Test с value 30");

    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1 после swap");
    ASSERT_EQ(sp2.use_count(), 1, "sp2 use_count должно быть 1 после swap");

    std::cout << "=== Тест shared_ptr::swap завершен ===\n\n";
}

// Тестирование self-assignment для shared_ptr
void test_shared_ptr_self_assignment() {
    std::cout << "=== Тест shared_ptr самоприсваивания ===\n";

    shared_ptr<Test> sp1(new Test(50));
    ASSERT_EQ(sp1.use_count(), 1, "sp1 use_count должно быть 1");

    sp1 = sp1; // Самоприсваивание
    ASSERT_EQ(sp1.use_count(), 1, "После самоприсваивания sp1 use_count должно быть 1");
    ASSERT_EQ(sp1->value, 50, "sp1 должно продолжать указывать на Test с value 50");

    std::cout << "=== Тест shared_ptr самоприсваивания завершен ===\n\n";
}


// Тестирование циклических ссылок для shared_ptr и weak_ptr
void test_cyclic_shared_ptr() {
    std::cout << "=== Тест циклических ссылок ===\n";

    struct Node {
        int value;
        shared_ptr<Node> next;
        weak_ptr<Node> prev; // Используем weak_ptr чтобы избежать циклов
        Node(int v) : value(v) { std::cout << "Node(" << value << ") создан.\n"; }
        
    };

    shared_ptr<Node> node1(new Node(1));
    shared_ptr<Node> node2(new Node(2));

    node1->next = node2;
    node2->prev = node1; // weak_ptr не увеличивает use_count

    ASSERT_EQ(node1.use_count(), 1, "node1 use_count должно быть 1");
    ASSERT_EQ(node2.use_count(), 2, "node2 use_count должно быть 2"); // Исправлено с 1 на 2

    // После выхода из блока, node1 и node2 будут уничтожены, так как нет циклов
    std::cout << "=== Тест циклических ссылок завершен ===\n\n";
}


int main() {
    test_unique_ptr();
    test_shared_ptr();
    test_shared_ptr_swap();
    test_shared_ptr_self_assignment();
    test_weak_ptr();
    test_cyclic_shared_ptr();

    return 0;
}
