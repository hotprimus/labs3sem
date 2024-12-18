#pragma once

#include <vector>
#include <utility>
#include <string>
#include "Person.h"

namespace Utils {

std::vector<std::pair<double, double>> createUniformRanges(double minValue, double maxValue, size_t numberOfRanges);
std::vector<Person> readPersonsFromCSV(const std::string& filePath);

}

