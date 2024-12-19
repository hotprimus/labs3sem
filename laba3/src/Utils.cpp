#include "Utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace Utils {

std::vector<std::pair<double, double>> createUniformRanges(double minValue, double maxValue, size_t numberOfRanges) {
    std::vector<std::pair<double, double>> ranges;

    if (minValue >= maxValue || numberOfRanges == 0) {
        return ranges; // Возвращаем пустой вектор
    }

    double rangeSize = (maxValue - minValue) / numberOfRanges;

    for (size_t i = 0; i < numberOfRanges; ++i) {
        double start = minValue + i * rangeSize;
        double end = start + rangeSize;
        ranges.emplace_back(start, end);
    }

    return ranges;
}

std::vector<Person> readPersonsFromCSV(const std::string& filePath) {
    std::vector<Person> persons;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filePath << std::endl;
        return persons;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name, ageStr, heightStr, weightStr;

        if (std::getline(ss, name, ',') &&
            std::getline(ss, ageStr, ',') &&
            std::getline(ss, heightStr, ',') &&
            std::getline(ss, weightStr, ',')) {

            int age = std::stoi(ageStr);
            double height = std::stod(heightStr);
            double weight = std::stod(weightStr);

            persons.emplace_back(name, age, height, weight);
        } else {
            std::cerr << "Ошибка чтения строки: " << line << std::endl;
        }
    }

    file.close();
    return persons;
}

}
