#include <iostream>
#include "PersonTest.h"
#include "HistogramTest.h"
#include "HistogramBuilderTest.h"

int main() {
    std::cout << "Running tests..." << std::endl;
    runPersonTests();
    runHistogramTests();
    runHistogramBuilderTests();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
