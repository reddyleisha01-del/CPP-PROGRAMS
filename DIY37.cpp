#include <iostream>
#include <memory>
using namespace std;

class Stack {
    unique_ptr<int[]> arr;     // replaces int* + new[] / delete[]
    int top, capacity;
public:
    Stack(int cap = 10) : arr(make_unique<int[]>(cap)), top(-1), capacity(cap) {}
    bool empty() const { return top < 0; }
    void push(int x) {
        if (top == capacity - 1) { cout << "Stack full\n"; return; }
        arr[++top] = x;
    }
    int pop() {
        if (top < 0) { cout << "Stack empty\n"; return -1; }
        return arr[top--];
    }
};   // no destructor needed: unique_ptr frees the buffer

int main() {
    auto s = make_unique<Stack>(5);   // no explicit delete anywhere
    s->push(10); s->push(20); s->push(30);
    cout << s->pop() << " " << s->pop() << " " << s->pop() << endl;
    return 0;
}

