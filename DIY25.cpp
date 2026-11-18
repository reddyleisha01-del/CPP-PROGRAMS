#include <iostream>
#include <exception>
using namespace std;

struct Overflow : exception {
    const char* what() const noexcept override { return "Stack overflow"; }
};
struct Underflow : exception {
    const char* what() const noexcept override { return "Stack underflow"; }
};

class Stack {
    int *arr;
    int top, capacity;
public:
    Stack(int cap) : top(-1), capacity(cap) { arr = new int[capacity]; }
    ~Stack() { delete[] arr; }
    void push(int x) {
        if (top == capacity - 1) throw Overflow();
        arr[++top] = x;
    }
    int pop() {
        if (top < 0) throw Underflow();
        return arr[top--];
    }
};

int main() {
    Stack s(2);
    try {
        s.push(1); s.push(2);
        s.push(3);               // overflow
    }
    catch (const Overflow &e) { cout << "Caught: " << e.what() << endl; }

    try {
        s.pop(); s.pop();
        s.pop();                 // underflow
    }
    catch (const Underflow &e) { cout << "Caught: " << e.what() << endl; }
    return 0;
}
