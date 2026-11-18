#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string w;
    cout << "Enter words (Ctrl+D / Ctrl+Z to end):\n";
    while (cin >> w) freq[w]++;

    string best;
    int bestCount = 0;
    for (auto &p : freq) {
        cout << p.first << " : " << p.second << endl;
        if (p.second > bestCount) { bestCount = p.second; best = p.first; }
    }
    if (bestCount) cout << "Most frequent: " << best << " (" << bestCount << ")\n";
    return 0;
}