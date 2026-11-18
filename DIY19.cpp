#include <iostream>
using namespace std;

class Shape {
    string name;
public:
    Shape(string n) : name(n) { cout << "Shape ctor: " << name << endl; }
    ~Shape() { cout << "Shape dtor\n"; }
};

class Polygon : public Shape {
    int sides;
public:
    Polygon(string n, int s) : Shape(n), sides(s) { cout << "Polygon ctor: sides=" << sides << endl; }
    ~Polygon() { cout << "Polygon dtor\n"; }
};

class Rectangle : public Polygon {
    double area;
public:
    Rectangle(double l, double b) : Polygon("Rectangle", 4), area(l * b) {
        cout << "Rectangle ctor: area=" << area << endl;
    }
    ~Rectangle() { cout << "Rectangle dtor\n"; }
};

int main() {
    Rectangle r(4, 5);
    return 0;
}
