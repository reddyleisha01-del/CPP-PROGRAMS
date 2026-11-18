
#include <iostream>
using namespace std;

double volume(double side) { return side * side * side; }                 // cube
double volume(double l, double b, double h) { return l * b * h; }         // cuboid
double volume(double r, double h) { return 3.14159 * r * r * h; }        // cylinder

int main() {
    cout << "Cube (3)          = " << volume(3.0) << endl;
    cout << "Cuboid (2,3,4)    = " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Cylinder (r=2,h=5)= " << volume(2.0, 5.0) << endl;
    return 0;
}
