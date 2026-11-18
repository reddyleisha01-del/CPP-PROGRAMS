#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << "  Construct #" << id << endl; }
    ~Tracer() { cout << "  Destruct #" << id << endl; }
};

int main() {
    cout << "Loop 1: with delete\n";
    for (int i = 1; i <= 3; ++i) {
        Tracer *t = new Tracer(i);
        delete t;
    }

    cout << "Loop 2: forgot delete (leak)\n";
    for (int i = 4; i <= 6; ++i) {
        Tracer *t = new Tracer(i);
        (void)t;   // no delete -> destructor never runs, memory leaks
    }
    return 0;
}
