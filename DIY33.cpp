#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<pair<string, int>> v = {{"Asha", 88}, {"Ravi", 95}, {"Meera", 72}, {"Kiran", 80}};

    sort(v.begin(), v.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) { return a.second < b.second; });

    for (auto &p : v) cout << p.first << " " << p.second << endl;
    return 0;
}
