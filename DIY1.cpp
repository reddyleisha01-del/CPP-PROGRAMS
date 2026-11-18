
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    int vowels = 0, consonants = 0;
    for (char ch : s) {
        if (isalpha((unsigned char)ch)) {
            char l = tolower(ch);
            if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') ++vowels;
            else ++consonants;
        }
    }
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    return 0;
}
