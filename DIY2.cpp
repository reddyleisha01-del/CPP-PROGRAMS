#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string normalise(string s) {
    string r;
    for (char c : s) if (isalpha((unsigned char)c)) r += tolower(c);
    sort(r.begin(), r.end());
    return r;
}

int main() {
    string a, b;
    cout << "Enter two words: ";
    cin >> a >> b;
    if (normalise(a) == normalise(b))
        cout << a << " and " << b << " are anagrams\n";
    else
        cout << a << " and " << b << " are NOT anagrams\n";
    return 0;
}
