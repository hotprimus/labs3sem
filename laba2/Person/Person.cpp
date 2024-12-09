#include "Person.h"

Person::Person() : name(""), age(0) {}

Person::Person(const std::string& name_, int age_) : name(name_), age(age_) {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::writeToFile(std::ostream& os) const {
    os << name << " " << age << "\n";
}

void Person::readFromFile(std::istream& is) {
    is >> name >> age;
}

bool Person::compareByName(const Person& a, const Person& b) {
    return a.name < b.name;
}

bool Person::compareByAge(const Person& a, const Person& b) {
    return a.age < b.age;
}
