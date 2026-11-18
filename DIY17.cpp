#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { int t = a % b; a = b; b = t; }
    return a;
}

class Fraction {
    int num, den;
    void simplify() {
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d == 0 ? 1 : d) { simplify(); }
    friend ostream& operator<<(ostream &os, const Fraction &f) {
        os << f.num << "/" << f.den;
        return os;
    }
    friend istream& operator>>(istream &is, Fraction &f) {
        char slash;
        int n, d;
        is >> n >> slash >> d;          // input like 6/8
        f = Fraction(n, d);             // simplified on construction
        return is;
    }
};

int main() {
    Fraction f;
    cout << "Enter a fraction (a/b): ";
    cin >> f;
    cout << "Simplified: " << f << endl;
    return 0;
}
