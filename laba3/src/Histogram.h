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

    Histogram();
    void addBin(const Range& range, const BinData& data);
    const std::map<Range, BinData>& getBins() const;
    size_t getTotalCount() const;
    std::vector<Range> getRanges() const;
    BinData getBinData(const Range& range) const;

private:
    std::map<Range, BinData> histogram_;
};

template <typename T>
Histogram<T>::Histogram() {}

template <typename T>
void Histogram<T>::addBin(const Range& range, const BinData& data) {
    histogram_[range] = data;
}

template <typename T>
const std::map<typename Histogram<T>::Range, typename Histogram<T>::BinData>& Histogram<T>::getBins() const {
    return histogram_;
}

template <typename T>
size_t Histogram<T>::getTotalCount() const {
    size_t total = 0;
    for (const auto& bin : histogram_) {
        total += bin.second.count;
    }
    return total;
}

template <typename T>
std::vector<typename Histogram<T>::Range> Histogram<T>::getRanges() const {
    std::vector<Range> ranges;
    for (const auto& bin : histogram_) {
        ranges.push_back(bin.first);
    }
    return ranges;
}

template <typename T>
typename Histogram<T>::BinData Histogram<T>::getBinData(const Range& range) const {
    auto it = histogram_.find(range);
    if (it != histogram_.end()) {
        return it->second;
    }
    return BinData{};
}


