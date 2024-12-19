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

    // Тест с пустыми данными
    {
        std::vector<Person> emptyData;
        auto ranges = Utils::createUniformRanges(20, 40, 2);
        HistogramBuilder<Person> builder;
        builder.setData(emptyData)
               .setRanges(ranges)
               .setCriterion([](const Person& p) { return static_cast<double>(p.getAge()); });

        Histogram<Person> histogram = builder.build();
        assert(histogram.getTotalCount() == 0);
        for (const auto& range : ranges) {
            auto binData = histogram.getBinData(range);
            assert(binData.count == 0);
            assert(binData.values.empty());
        }
    }

    // Тест с данными вне диапазонов
    {
        std::vector<Person> data = {
            Person("Test1", 10, 160.0, 50.0),
            Person("Test2", 50, 170.0, 60.0)
        };
        auto ranges = Utils::createUniformRanges(20, 40, 2);
        HistogramBuilder<Person> builder;
        builder.setData(data)
               .setRanges(ranges)
               .setCriterion([](const Person& p) { return static_cast<double>(p.getAge()); });

        Histogram<Person> histogram = builder.build();
        assert(histogram.getTotalCount() == 0);
        for (const auto& range : ranges) {
            auto binData = histogram.getBinData(range);
            assert(binData.count == 0);
            assert(binData.values.empty());
        }
    }

    // Тест с одним диапазоном
    {
        std::vector<Person> data = {
            Person("Test1", 25, 160.0, 50.0),
            Person("Test2", 30, 170.0, 60.0),
            Person("Test3", 35, 180.0, 70.0)
        };
        auto ranges = Utils::createUniformRanges(20, 40, 1);
        HistogramBuilder<Person> builder;
        builder.setData(data)
               .setRanges(ranges)
               .setCriterion([](const Person& p) { return static_cast<double>(p.getAge()); });

        Histogram<Person> histogram = builder.build();
        assert(histogram.getTotalCount() == 3);
        auto binData = histogram.getBinData(ranges[0]);
        assert(binData.count == 3);
    }

    // Тест с одинаковыми минимальным и максимальным значениями
    {
        std::vector<Person> data = {
            Person("Test1", 25, 160.0, 50.0)
        };
        auto ranges = Utils::createUniformRanges(25, 25, 1);
        assert(ranges.size() == 0); // В этом случае диапазоны не создаются
    }

    // Тест с некорректными параметрами диапазонов
    {
        std::vector<Person> data = {
            Person("Test1", 25, 160.0, 50.0)
        };
        auto ranges = Utils::createUniformRanges(30, 20, 2); // minValue > maxValue
        assert(ranges.empty()); // Ожидаем пустой вектор диапазонов
    }

    // Основной тест
    {
        std::vector<Person> data = Utils::readPersonsFromCSV("resources/data.csv");
        assert(!data.empty());

        auto ranges = Utils::createUniformRanges(20, 40, 2);

        HistogramBuilder<Person> builder;
        builder.setData(data)
               .setRanges(ranges)
               .setCriterion([](const Person& p) { return static_cast<double>(p.getAge()); });

        Histogram<Person> histogram = builder.build();
        const auto& histData = histogram.getBins();
        assert(histData.size() == 2);

        auto it = histData.find(std::make_pair(20.0, 30.0));
        assert(it != histData.end());
        size_t count1 = it->second.count;
        assert(count1 > 0);

        it = histData.find(std::make_pair(30.0, 40.0));
        assert(it != histData.end());
        size_t count2 = it->second.count;
        assert(count2 > 0);
    }

    std::cout << "HistogramBuilder tests passed!" << std::endl;
}

