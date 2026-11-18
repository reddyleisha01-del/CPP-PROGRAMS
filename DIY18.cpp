#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}
    void show() const { cout << "Name: " << name << ", ID: " << id; }
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(string n, int i, int t) : Employee(n, i), teamSize(t) {}
    void display() const { show(); cout << ", Team size: " << teamSize << endl; }
};

class Engineer : public Employee {
    string skill;
public:
    Engineer(string n, int i, string s) : Employee(n, i), skill(s) {}
    void display() const { show(); cout << ", Skill: " << skill << endl; }
};

int main() {
    Manager m("Asha", 101, 8);
    Engineer e("Ravi", 202, "Verilog");
    m.display();
    e.display();
    return 0;
}
