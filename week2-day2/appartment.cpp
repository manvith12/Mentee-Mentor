// week1-day3 queue q1, same old appartment question //

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int  n, m, k;

    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    queue<int> qa;
    queue<int> qb;

    for (int i = 0; i < n; i++) {
        qa.push(a[i]);
    }
    for (int i = 0; i < m; i++) {
        qb.push(b[i]);
    }

    int count = 0;

    while (!qa.empty() && !qb.empty()) {
        if (qa.front() > qb.front() + k) {
            qb.pop();
        } else if (qa.front() < qb.front() - k) {
            qa.pop();
        } else {
            qa.pop();
            qb.pop();
            count++;
        }
    }
    cout << count << endl;
    return 0;
}