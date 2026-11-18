#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n = "Unknown") : name(n) { cout << "Person ctor\n"; }
    void show() const { cout << "Name: " << name << endl; }
};

class Student : virtual public Person {
public:
    Student(string n) : Person(n) { cout << "Student ctor\n"; }
};

class Employee : virtual public Person {
public:
    Employee(string n) : Person(n) { cout << "Employee ctor\n"; }
};

class TA : public Student, public Employee {
public:
    TA(string n) : Person(n), Student(n), Employee(n) { cout << "TA ctor\n"; }
};

int main() {
    TA t("Meera");
    t.show();   // unambiguous: Person appears once
    return 0;
}
