#pragma once

#include <QtTest>

class SortingTests : public QObject
{
    Q_OBJECT

private slots:
    void testQuickSort();
    void testHeapSort();
    void testShellSort();
};


