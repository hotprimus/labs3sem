#pragma once

#include <iostream>
#include <cassert>
#include "../Histogram.h"
#include "../Person.h"

void runHistogramTests() {
    std::cout << "Running Histogram tests..." << std::endl;

    Histogram<Person> histogram;

    // Тестирование добавления и получения бинов
    Histogram<Person>::Range range1 = {0.0, 10.0};
    Histogram<Person>::BinData binData1;
    binData1.count = 2;
    binData1.values = {2.0, 5.0};
    binData1.mean = 3.5;
    binData1.stdDev = 1.5;

    histogram.addBin(range1, binData1);

    auto retrievedBinData = histogram.getBinData(range1);
    assert(retrievedBinData.count == 2);
    assert(retrievedBinData.mean == 3.5);
    assert(retrievedBinData.stdDev == 1.5);

    // Тестирование общего количества элементов
    size_t totalCount = histogram.getTotalCount();
    assert(totalCount == 2);

    // Тестирование получения диапазонов
    auto ranges = histogram.getRanges();
    assert(ranges.size() == 1);
    assert(ranges[0] == range1);

    std::cout << "Histogram tests passed!" << std::endl;
}
