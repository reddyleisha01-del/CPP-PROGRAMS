#include <iostream>
using namespace std;

class Counter {
    int count;
    static int created;
    static int alive;
public:
    Counter() : count(0) { ++created; ++alive; }
    Counter(const Counter &o) : count(o.count) { ++created; ++alive; }
    ~Counter() { --alive; }
    void increment() { ++count; }
    void reset() { count = 0; }
    int get() const { return count; }
    static int totalCreated() { return created; }
    static int currentlyAlive() { return alive; }
};
int Counter::created = 0;
int Counter::alive = 0;

int main() {
    Counter a, b;
    {
        Counter c;
        cout << "Created = " << Counter::totalCreated()
             << ", Alive = " << Counter::currentlyAlive() << endl;
    }
    cout << "Created = " << Counter::totalCreated()
         << ", Alive = " << Counter::currentlyAlive() << endl;
    return 0;
}
