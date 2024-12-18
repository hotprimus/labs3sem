#pragma once

#include <vector>
#include <map>
#include <functional>
#include <utility>

template <typename T>
class Histogram {
public:
    using Range = std::pair<double, double>;
    using CriterionFunction = std::function<double(const T&)>;

    struct BinData {
        size_t count = 0;
        std::vector<double> values;
        double mean = 0.0;
        double stdDev = 0.0;
    };

    Histogram(const std::map<Range, BinData>& histogramData);
    const std::map<Range, BinData>& getHistogram() const;

private:
    std::map<Range, BinData> histogram_;
};

template <typename T>
Histogram<T>::Histogram(const std::map<Range, BinData>& histogramData)
    : histogram_(histogramData) {}

template <typename T>
const std::map<typename Histogram<T>::Range, typename Histogram<T>::BinData>& Histogram<T>::getHistogram() const {
    return histogram_;
}
