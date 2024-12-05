#include "SortingTests.h"
#include "../TypeOfSorts/QuickSorter.h"
#include "../TypeOfSorts/HeapSorter.h"
#include "../TypeOfSorts/ShellSorter.h"
#include "../Sequence/DynamicArray.h"

void SortingTests::testQuickSort()
{
    DynamicArray<int> data;
    data.append(5);
    data.append(2);
    data.append(9);
    data.append(1);
    data.append(5);
    data.append(6);

    int expected[] = {1, 2, 5, 5, 6, 9};

    QuickSorter<int> sorter;
    sorter.sort(&data, [](const int& a, const int& b) { return a < b; });

    for (int i = 0; i < data.getSize(); ++i)
        QCOMPARE(data[i], expected[i]);
}

void SortingTests::testHeapSort()
{
    DynamicArray<int> data;
    data.append(3);
    data.append(0);
    data.append(-2);
    data.append(10);
    data.append(7);

    int expected[] = {-2, 0, 3, 7, 10};

    HeapSorter<int> sorter;
    sorter.sort(&data, [](const int& a, const int& b) { return a < b; });

    for (int i = 0; i < data.getSize(); ++i)
        QCOMPARE(data[i], expected[i]);
}

void SortingTests::testShellSort()
{
    DynamicArray<int> data;
    data.append(12);
    data.append(34);
    data.append(54);
    data.append(2);
    data.append(3);

    int expected[] = {2, 3, 12, 34, 54};

    ShellSorter<int> sorter;
    sorter.sort(&data, [](const int& a, const int& b) { return a < b; });

    for (int i = 0; i < data.getSize(); ++i)
        QCOMPARE(data[i], expected[i]);
}

QTEST_MAIN(SortingTests)
#include "SortingTests.moc"
