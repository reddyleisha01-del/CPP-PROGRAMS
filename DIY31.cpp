
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue {
    T data[100];
    int frontIdx = 0, count = 0;
public:
    bool empty() const { return count == 0; }
    bool full() const { return count == 100; }
    void enqueue(T x) {
        if (full()) { cout << "Queue full\n"; return; }
        data[(frontIdx + count) % 100] = x;
        ++count;
    }
    T dequeue() {
        T v = data[frontIdx];
        frontIdx = (frontIdx + 1) % 100;
        --count;
        return v;
    }
    T front() const { return data[frontIdx]; }
};

int main() {
    Queue<string> q;
    q.enqueue("alpha");
    q.enqueue("beta");
    q.enqueue("gamma");
    cout << "front = " << q.front() << endl;
    while (!q.empty()) cout << q.dequeue() << " ";
    cout << endl;
    return 0;
}
