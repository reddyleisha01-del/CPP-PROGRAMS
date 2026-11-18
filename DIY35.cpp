
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {2, 3, 4, 5, 6};

    long long product = accumulate(v.begin(), v.end(), 1LL,
                                   [](long long p, int x) { return p * x; });
    int evenSum = accumulate(v.begin(), v.end(), 0,
                             [](int s, int x) { return (x % 2 == 0) ? s + x : s; });

    cout << "Product  = " << product << endl;   // 720
    cout << "Even sum = " << evenSum << endl;    // 12
    return 0;
}
