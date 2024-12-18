#include <iostream>
#include <cassert>
#include "PersonTest.h"
#include "HistogramBuilderTest.h"

int main() {
    std::cout << "Running tests..." << std::endl;
    runPersonTests();
    runHistogramBuilderTests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
