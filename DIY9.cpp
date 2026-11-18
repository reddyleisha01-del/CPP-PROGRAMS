#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    void setData(double r, double i) { real = r; imag = i; }
    void display() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

int main() {
    Complex arr[3];
    arr[0].setData(2, 3);
    arr[1].setData(1, -4);
    arr[2].setData(0, 5);
    for (int i = 0; i < 3; ++i) arr[i].display();
    return 0;
}
