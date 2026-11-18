#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string &msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override { cout << "[CONSOLE] " << msg << endl; }
};

class FileLogger : public Logger {
    ofstream out;
public:
    FileLogger(const string &f) : out(f, ios::app) {}
    void write(const string &msg) override { out << "[FILE] " << msg << "\n"; }
};

int main() {
    Logger *lg = nullptr;
    int choice;
    cout << "Choose logger (1 = console, 2 = file): ";
    cin >> choice;

    if (choice == 1) lg = new ConsoleLogger();
    else             lg = new FileLogger("app.log");

    lg->write("System started");
    lg->write("Test passed");
    if (choice == 2) cout << "Written to app.log\n";

    delete lg;
    return 0;
}
