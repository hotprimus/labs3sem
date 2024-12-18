#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include "../HistogramBuilder.h"
#include "../Person.h"
#include "../Utils.h"

void runHistogramBuilderTests() {
    std::cout << "Running HistogramBuilder tests..." << std::endl;

    std::vector<Person> data = Utils::readPersonsFromCSV("resources/data.csv");
    assert(!data.empty());

    auto ranges = Utils::createUniformRanges(20, 40, 2);

    HistogramBuilder<Person> builder;
    builder.setData(data)
           .setRanges(ranges)
           .setCriterion([](const Person& p) { return static_cast<double>(p.getAge()); });

    Histogram<Person> histogram = builder.build();
    const auto& histData = histogram.getHistogram();
    assert(histData.size() == 2);

    auto it = histData.find(std::make_pair(20.0, 30.0));
    assert(it != histData.end());
    size_t count1 = it->second.count;
    assert(count1 > 0);

    it = histData.find(std::make_pair(30.0, 40.0));
    assert(it != histData.end());
    size_t count2 = it->second.count;
    assert(count2 > 0);

    std::cout << "HistogramBuilder tests passed!" << std::endl;
}
