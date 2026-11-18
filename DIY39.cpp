
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

long counter = 0;
mutex m;

void add(int times) {
    for (int i = 0; i < times; ++i) {
#ifdef USE_LOCK
        lock_guard<mutex> lk(m);
#endif
        ++counter;
    }
}

int main() {
    thread t1(add, 100000);
    thread t2(add, 100000);
    t1.join(); t2.join();
    cout << "counter = " << counter << " (expected 200000)\n";
    return 0;
}
