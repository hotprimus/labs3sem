#ifndef HISTOGRAMBUILDER_H
#define HISTOGRAMBUILDER_H

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
    std::map<Range, typename Histogram<T>::BinData> histogramData;

    for (const auto& range : ranges_) {
        histogramData[range] = typename Histogram<T>::BinData();
    }

    for (const auto& item : data_) {
        double value = criterion_(item);
        for (const auto& range : ranges_) {
            if (value >= range.first && value < range.second) {
                auto& binData = histogramData[range];
                binData.count++;
                binData.values.push_back(value);
                break;
            }
        }
    }

    for (auto& entry : histogramData) {
        auto& binData = entry.second;
        size_t n = binData.values.size();
        if (n > 0) {
            double sum = std::accumulate(binData.values.begin(), binData.values.end(), 0.0);
            double mean = sum / n;
            double sq_sum = std::inner_product(binData.values.begin(), binData.values.end(), binData.values.begin(), 0.0);
            double stdDev = std::sqrt(sq_sum / n - mean * mean);
            binData.mean = mean;
            binData.stdDev = stdDev;
        } else {
            binData.mean = 0.0;
            binData.stdDev = 0.0;
        }
    }

    return Histogram<T>(histogramData);
}

#endif // HISTOGRAMBUILDER_H
