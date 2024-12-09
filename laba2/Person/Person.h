#pragma once

#include <string>
#include <iostream>

class Person {
public:
    Person();
    Person(const std::string& name_, int age_);

    std::string getName() const;
    int getAge() const;

    void writeToFile(std::ostream& os) const;
    void readFromFile(std::istream& is);

    static bool compareByName(const Person& a, const Person& b);
    static bool compareByAge(const Person& a, const Person& b);

private:
    std::string name;
    int age;
};
