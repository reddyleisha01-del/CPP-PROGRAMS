#include <iostream>
using namespace std;

class Order {
    int id;
    static int nextId;
public:
    Order() : id(nextId++) {}
    int getId() const { return id; }
};
int Order::nextId = 1001;

int main() {
    Order a, b, c;
    cout << a.getId() << " " << b.getId() << " " << c.getId() << endl;  // 1001 1002 1003
    return 0;
}
