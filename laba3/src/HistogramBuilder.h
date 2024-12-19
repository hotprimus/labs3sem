#pragma once

#include <vector>
#include <map>
#include <functional>
#include <numeric>
#include <cmath>
#include "Histogram.h"

template <typename T>
class HistogramBuilder {
public:
    using Range = typename Histogram<T>::Range;
    using CriterionFunction = typename Histogram<T>::CriterionFunction;

    HistogramBuilder& setData(const std::vector<T>& data);
    HistogramBuilder& setCriterion(const CriterionFunction& criterion);
    HistogramBuilder& setRanges(const std::vector<Range>& ranges);

    Histogram<T> build();

private:
    std::vector<T> data_;
    CriterionFunction criterion_;
    std::vector<Range> ranges_;
};

template <typename T>
HistogramBuilder<T>& HistogramBuilder<T>::setData(const std::vector<T>& data) {
    data_ = data;
    return *this;
}

template <typename T>
HistogramBuilder<T>& HistogramBuilder<T>::setCriterion(const CriterionFunction& criterion) {
    criterion_ = criterion;
    return *this;
}

template <typename T>
HistogramBuilder<T>& HistogramBuilder<T>::setRanges(const std::vector<Range>& ranges) {
    ranges_ = ranges;
    return *this;
}

template <typename T>
Histogram<T> HistogramBuilder<T>::build() {
    Histogram<T> histogram;

    // Инициализация пустых диапазонов
    for (const auto& range : ranges_) {
        histogram.addBin(range, typename Histogram<T>::BinData{});
    }

    // Распределение данных по диапазонам
    for (const auto& item : data_) {
        double value = criterion_(item);
        bool found = false;
        for (const auto& range : ranges_) {
            if (value >= range.first && value < range.second) {
                auto binData = histogram.getBinData(range);
                binData.count++;
                binData.values.push_back(value);
                histogram.addBin(range, binData);
                found = true;
                break;
            }
        }
        if (!found) {
            // Значение не попало в диапазоны (можно обработать, если необходимо)
        }
    }

    // Вычисление статистики для каждого диапазона
    for (const auto& range : ranges_) {
        auto binData = histogram.getBinData(range);
        size_t n = binData.values.size();
        if (n > 0) {
            double sum = std::accumulate(binData.values.begin(), binData.values.end(), 0.0);
            double mean = sum / n;
            double sq_sum = std::inner_product(binData.values.begin(), binData.values.end(), binData.values.begin(), 0.0);
            double stdDev = std::sqrt(sq_sum / n - mean * mean);
            binData.mean = mean;
            binData.stdDev = stdDev;
            histogram.addBin(range, binData);
        } else {
            binData.mean = 0.0;
            binData.stdDev = 0.0;
            histogram.addBin(range, binData);
        }
    }

    return histogram;
}


