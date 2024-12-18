#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& name, int age, double height, double weight);
    std::string getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;
private:
    std::string name_;
    int age_;
    double height_;
    double weight_;
};

#endif // PERSON_H
