#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    ofstream out("records.txt");
    out << "Asha 91\nRavi 78\nMeera 88\n";
    out.close();

    ifstream in("records.txt");
    if (!in) { cerr << "cannot open records.txt\n"; return 1; }

    Student arr[50];
    int n = 0;
    while (n < 50 && in >> arr[n].name >> arr[n].marks) ++n;

    int top = 0;
    for (int i = 0; i < n; ++i) {
        cout << arr[i].name << " " << arr[i].marks << endl;
        if (arr[i].marks > arr[top].marks) top = i;
    }
    if (n) cout << "Topper: " << arr[top].name << " (" << arr[top].marks << ")\n";
    return 0;
}
