#include <iostream>
using namespace std;

class Matrix {
    int m, n;
    int **data;
public:
    Matrix(int rows, int cols) : m(rows), n(cols) {
        data = new int*[m];
        for (int i = 0; i < m; ++i) {
            data[i] = new int[n];
            for (int j = 0; j < n; ++j) data[i][j] = 0;
        }
    }
    Matrix(const Matrix &o) : m(o.m), n(o.n) {          // deep copy
        data = new int*[m];
        for (int i = 0; i < m; ++i) {
            data[i] = new int[n];
            for (int j = 0; j < n; ++j) data[i][j] = o.data[i][j];
        }
    }
    ~Matrix() {
        for (int i = 0; i < m; ++i) delete[] data[i];
        delete[] data;
    }
    void set(int i, int j, int v) { data[i][j] = v; }
    void show() const {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix a(2, 3);
    int k = 1;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j) a.set(i, j, k++);
    Matrix b = a;        // deep copy
    b.set(0, 0, 99);     // does not affect a
    cout << "a:\n"; a.show();
    cout << "b:\n"; b.show();
    return 0;
}
