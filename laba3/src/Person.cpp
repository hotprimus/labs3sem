#include "Person.h"

Person::Person(const std::string& name, int age, double height, double weight)
    : name_(name), age_(age), height_(height), weight_(weight) {}

std::string Person::getName() const {
    return name_;
}

int Person::getAge() const {
    return age_;
}

double Person::getHeight() const {
    return height_;
}

double Person::getWeight() const {
    return weight_;
}
