#include <iostream>
using namespace std;

class Money {
    long rupees, paise;
    void normalise() {
        long total = rupees * 100 + paise;
        rupees = total / 100;
        paise = total % 100;
    }
public:
    Money(long r = 0, long p = 0) : rupees(r), paise(p) { normalise(); }
    Money operator+(const Money &o) const {
        return Money(rupees + o.rupees, paise + o.paise);       // carry handled
    }
    Money operator-(const Money &o) const {
        long total = (rupees * 100 + paise) - (o.rupees * 100 + o.paise);
        return Money(0, total);                                  // borrow handled
    }
    void show() const { cout << "Rs " << rupees << "." << (paise < 10 ? "0" : "") << paise << endl; }
};

int main() {
    Money a(10, 75), b(5, 50);
    (a + b).show();   // Rs 16.25
    (a - b).show();   // Rs 5.25
    (b - a).show();   // negative result shown as total in paise normalised
    return 0;
}
