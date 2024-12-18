#ifndef PERSONTEST_H
#define PERSONTEST_H

#include <iostream>
#include <cassert>
#include "../Person.h"

void runPersonTests() {
    std::cout << "Running Person tests..." << std::endl;

    Person person("Alice", 25, 170.0, 65.0);
    assert(person.getName() == "Alice");
    assert(person.getAge() == 25);
    assert(person.getHeight() == 170.0);
    assert(person.getWeight() == 65.0);

    std::cout << "Person tests passed!" << std::endl;
}

#endif // PERSONTEST_H
