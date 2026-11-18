#include <iostream>
using namespace std;

class Time {
    int hh, mm;
public:
    Time(int h = 0, int m = 0) : hh(h), mm(m) {}
    friend Time laterOf(Time a, Time b);
    void show() const {
        cout << (hh < 10 ? "0" : "") << hh << ":" << (mm < 10 ? "0" : "") << mm << endl;
    }
};

Time laterOf(Time a, Time b) {
    if (a.hh > b.hh) return a;
    if (a.hh < b.hh) return b;
    return (a.mm >= b.mm) ? a : b;
}

int main() {
    Time t1(9, 45), t2(14, 5);
    cout << "Later time: ";
    laterOf(t1, t2).show();
    return 0;
}
