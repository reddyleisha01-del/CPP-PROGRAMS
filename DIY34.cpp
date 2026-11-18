
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;   // keeps the 3 largest
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        minHeap.push(x);
        if (minHeap.size() > 3) minHeap.pop();
    }

    vector<int> top;
    while (!minHeap.empty()) { top.push_back(minHeap.top()); minHeap.pop(); }

    cout << "Top 3: ";
    for (int i = (int)top.size() - 1; i >= 0; --i) cout << top[i] << " ";
    cout << endl;
    return 0;
}
