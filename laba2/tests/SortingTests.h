#pragma once

#include <QObject>

class SortingTests : public QObject {
    Q_OBJECT 

private slots:
    void testIntegerSorting();
    void testPersonSorting();
    void testPersonFileSorting();
    void benchmarkIntegerSorters();
};
