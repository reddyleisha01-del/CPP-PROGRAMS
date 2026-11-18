#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("in.txt");
    if (!in) { cerr << "cannot open in.txt\n"; return 1; }
    ofstream out("out.txt");
    if (!out) { cerr << "cannot open out.txt\n"; return 1; }

    string line;
    int n = 1;
    while (getline(in, line)) {
        out << n << ": " << line << "\n";
        ++n;
    }
    cout << "Copied " << (n - 1) << " line(s) to out.txt\n";
    return 0;
}
