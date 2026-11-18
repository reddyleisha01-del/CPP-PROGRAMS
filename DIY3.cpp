#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line, w;
    cout << "Enter a sentence: ";
    getline(cin, line);

    stringstream ss(line);
    vector<string> words;
    while (ss >> w) words.push_back(w);

    for (int i = (int)words.size() - 1; i >= 0; --i) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    return 0;
}
