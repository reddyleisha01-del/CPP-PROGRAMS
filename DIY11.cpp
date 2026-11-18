#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top, capacity;
public:
    Stack(int cap = 10) : top(-1), capacity(cap) { arr = new int[capacity]; }
    ~Stack() { delete[] arr; cout << "Stack buffer released\n"; }
    bool empty() const { return top < 0; }
    bool full() const { return top == capacity - 1; }
    void push(int x) {
        if (full()) { cout << "Stack full\n"; return; }
        arr[++top] = x;
    }
    int pop() {
        if (empty()) { cout << "Stack empty\n"; return -1; }
        return arr[top--];
    }
};

int main() {
    Stack s(5);
    s.push(10); s.push(20); s.push(30);
    cout << s.pop() << " " << s.pop() << " " << s.pop() << endl;
    s.pop();   // empty message
    return 0;
}
