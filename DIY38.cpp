
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct Shape {
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~Shape() {}
};
struct Circle : Shape {
    double r;
    Circle(double r) : r(r) {}
    double area() const override { return 3.14159 * r * r; }
    string name() const override { return "circle"; }
};
struct Square : Shape {
    double s;
    Square(double s) : s(s) {}
    double area() const override { return s * s; }
    string name() const override { return "square"; }
};
struct Triangle : Shape {
    double b, h;
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string name() const override { return "triangle"; }
};

unique_ptr<Shape> makeShape(const string &kind) {
    if (kind == "circle")   return make_unique<Circle>(2.0);
    if (kind == "square")   return make_unique<Square>(3.0);
    if (kind == "triangle") return make_unique<Triangle>(4.0, 5.0);
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string kind;
    cout << "Enter shape names (circle/square/triangle), 'done' to stop:\n";
    while (cin >> kind && kind != "done") {
        auto s = makeShape(kind);
        if (s) shapes.push_back(move(s));
        else cout << "Unknown shape: " << kind << endl;
    }
    for (auto &s : shapes)
        cout << s->name() << " area = " << s->area() << endl;
    return 0;
}
