
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class InsufficientFunds : public exception {
    string msg;
public:
    InsufficientFunds(double need, double have)
        : msg("Insufficient funds: need " + to_string(need) + ", have " + to_string(have)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class BankAccount {
    string owner;
    double balance;
public:
    BankAccount(string o, double b) : owner(o), balance(b) {}
    void deposit(double a) { if (a > 0) balance += a; }
    void withdraw(double a) {
        if (a > balance) throw InsufficientFunds(a, balance);
        balance -= a;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount acc("Asha", 1000);
    try {
        acc.withdraw(300);
        cout << "Balance = " << acc.getBalance() << endl;
        acc.withdraw(2000);
    }
    catch (const InsufficientFunds &e) {
        cout << "[ERR] " << e.what() << endl;
    }
    return 0;
}
