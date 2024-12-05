// week1-day3 priotityqueue q1, same old appsartment question //


#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    priority_queue<int> a;
    priority_queue<int> b;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push(temp);
    }

    for (int i = 0; i < m; ++i) {
        int temp;
        cin >> temp;
        b.push(temp);
    }

    int count = 0;

    while (!a.empty() && !b.empty()) {
        if (a.top() > b.top() + k) {
            a.pop();
        } else if (a.top() < b.top() - k) {
            b.pop();
        } else {
            a.pop();
            b.pop();
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

