#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Person {
public:
    Person(std::string name, int age) : name_(std::move(name)), age_(age) {}
    virtual ~Person() = default;

    const std::string& name() const noexcept { return name_; }
    int age() const noexcept { return age_; }
    virtual std::string role_details() const = 0;

    void introduce() const {
        std::cout << name_ << " (" << age_ << ") - " << role_details() << '\n';
    }

private:
    std::string name_;
    int age_;
};

class Teacher final : public Person {
public:
    Teacher(std::string name, int age, std::string subject)
        : Person(std::move(name), age), subject_(std::move(subject)) {}

    std::string role_details() const override {
        return subject_ + " ogretmeni";
    }

private:
    std::string subject_;
};

class Student final : public Person {
public:
    Student(std::string name, int age, std::string student_number)
        : Person(std::move(name), age), student_number_(std::move(student_number)) {}

    std::string role_details() const override {
        return "ogrenci numarasi: " + student_number_;
    }

private:
    std::string student_number_;
};

int main() {
    std::vector<std::unique_ptr<Person>> people;
    people.push_back(std::make_unique<Teacher>("Halit Oztekin", 48, "Bilgisayar Mimarisi"));
    people.push_back(std::make_unique<Student>("Furkan", 25, "B210109048"));

    for (const auto& person : people) {
        person->introduce();
    }
}
