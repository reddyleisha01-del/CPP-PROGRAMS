#include <iostream>
using namespace std;

template <typename T>
void swapVals(T &a, T &b) { T t = a; a = b; b = t; }

template <typename T>
T findMax(T arr[], int n) {
    T m = arr[0];
    for (int i = 1; i < n; ++i) if (arr[i] > m) m = arr[i];
    return m;
}

int main() {
    int a = 3, b = 9;
    swapVals(a, b);
    cout << "ints swapped: " << a << " " << b << endl;

    double x = 1.5, y = 7.25;
    swapVals(x, y);
    cout << "doubles swapped: " << x << " " << y << endl;

    int ai[] = {4, 17, 9, 2};
    double ad[] = {2.5, 8.75, 3.1};
    cout << "max int    = " << findMax(ai, 4) << endl;
    cout << "max double = " << findMax(ad, 3) << endl;
    return 0;
}
