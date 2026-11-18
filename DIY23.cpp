#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base ctor\n"; }
    ~Base() { cout << "Base dtor\n"; }          // NOT virtual -> bug
    // virtual ~Base() { cout << "Base dtor\n"; }  // <- fix: uncomment this, delete the line above
};

class Derived : public Base {
    int *buf;
public:
    Derived() { buf = new int[100]; cout << "Derived ctor (allocated)\n"; }
    ~Derived() { delete[] buf; cout << "Derived dtor (freed)\n"; }
};

int main() {
    Base *p = new Derived();
    delete p;   // without virtual: only Base dtor runs -> buf leaks
    return 0;
}
