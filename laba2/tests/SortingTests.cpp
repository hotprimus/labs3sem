#include "SortingTests.h"

#include <QtTest>
#include <QDebug>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>

#include "../TypeOfSorts/ShellSorter.h"
#include "../TypeOfSorts/QuickSorter.h"
#include "../TypeOfSorts/HeapSorter.h"
#include "../Person/Person.h"
#include "../Sequence/DynamicArray.h"

void SortingTests::testIntegerSorting()
{
    std::vector<int> dataVec = {5, 3, 8, 4, 2};
    std::vector<int> expected = {2, 3, 4, 5, 8};

    DynamicArray<int> dynData;
    for (int val : dataVec) {
        dynData.append(val);
    }

    ShellSorter<int> sorter;
    sorter.sort(&dynData[0], dynData.getSize());

    // Проверка результатов
    for (size_t i = 0; i < dynData.getSize(); ++i) {
        QCOMPARE(dynData[i], expected[i]);
    }
}

void SortingTests::testPersonSorting()
{
    DynamicArray<Person> dynData;
    dynData.append(Person("Alice", 30));
    dynData.append(Person("Bob", 25));
    dynData.append(Person("Charlie", 35));

    QuickSorter<Person> sorter;
    sorter.sort(&dynData[0], dynData.getSize(), Person::compareByAge);

    QVERIFY(dynData[0].getAge() <= dynData[1].getAge());
    QVERIFY(dynData[1].getAge() <= dynData[2].getAge());
}

void SortingTests::testPersonFileSorting()
{

    std::ofstream outFile("temp_persons.txt");
    outFile << "Alice 30\nBob 25\nCharlie 35\n";
    outFile.close();

    DynamicArray<Person> dynData;
    std::ifstream inFile("temp_persons.txt");
    while (!inFile.eof()) {
        Person p;
        p.readFromFile(inFile);
        if (!p.getName().empty()) {
            dynData.append(p);
        }
    }
    inFile.close();

    HeapSorter<Person> sorter;
    sorter.sort(&dynData[0], dynData.getSize(), Person::compareByName);

    QVERIFY(dynData[0].getName() <= dynData[1].getName());
    QVERIFY(dynData[1].getName() <= dynData[2].getName());
    std::remove("temp_persons.txt");
}

void SortingTests::benchmarkIntegerSorters()
{

    const int dataSize = 10000;
    std::vector<int> originalData(dataSize);
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist(0, 100000);

    for (int& val : originalData) {
        val = dist(rng);
    }

    // Сортировка Шелла
    {
        DynamicArray<int> dynData;
        for (int val : originalData) {
            dynData.append(val);
        }

        ShellSorter<int> shellSorter;
        auto start = std::chrono::high_resolution_clock::now();
        shellSorter.sort(&dynData[0], dynData.getSize());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durationShell = end - start;

        QVERIFY(std::is_sorted(&dynData[0], &dynData[0] + dynData.getSize()));
        qInfo() << "ShellSorter Time:" << durationShell.count() << "ms";
    }

    // Быстрая сортировка
    {
        DynamicArray<int> dynData;
        for (int val : originalData) {
            dynData.append(val);
        }

        QuickSorter<int> quickSorter;
        auto start = std::chrono::high_resolution_clock::now();
        quickSorter.sort(&dynData[0], dynData.getSize());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durationQuick = end - start;

        QVERIFY(std::is_sorted(&dynData[0], &dynData[0] + dynData.getSize()));
        qInfo() << "QuickSorter Time:" << durationQuick.count() << "ms";
    }

    // Сортировка кучей
    {
        DynamicArray<int> dynData;
        for (int val : originalData) {
            dynData.append(val);
        }

        HeapSorter<int> heapSorter;
        auto start = std::chrono::high_resolution_clock::now();
        heapSorter.sort(&dynData[0], dynData.getSize());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> durationHeap = end - start;

        QVERIFY(std::is_sorted(&dynData[0], &dynData[0] + dynData.getSize()));
        qInfo() << "HeapSorter Time:" << durationHeap.count() << "ms";
    }
}


QTEST_MAIN(SortingTests)
#include "SortingTests.moc"
