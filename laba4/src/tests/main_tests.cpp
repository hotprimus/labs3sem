#include <iostream>
#include "GraphTest.h"
#include "AlgorithmsTest.h"
#include "HasseDiagramTest.h"

int main() {
    std::cout << "Running tests..." << std::endl;
    runGraphTests();
    runAlgorithmsTests();
    runHasseDiagramTests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
