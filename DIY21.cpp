#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual double calculateInterest() const = 0;
    virtual void name() const = 0;
    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}
    double calculateInterest() const override { return balance * 0.04; }
    void name() const override { cout << "Savings "; }
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}
    double calculateInterest() const override { return balance * 0.01; }
    void name() const override { cout << "Current "; }
};

int main() {
    Account *accts[] = { new Savings(10000), new Current(20000), new Savings(5000) };
    for (Account *a : accts) {
        a->name();
        cout << "interest = " << a->calculateInterest() << endl;
    }
    for (Account *a : accts) delete a;
    return 0;
}
