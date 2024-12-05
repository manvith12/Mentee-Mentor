// week1-day5 , upperbound q2, concerts✨ //
//link: https://cses.fi/problemset/task/1091

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> tp;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        tp.insert(p);
    }

    while (m--) {
        int x;
        cin >> x;
        auto it = tp.upper_bound(x);
        if (it == tp.begin()) {
            cout << "-1\n";
        } else {
            --it;
            cout << *it << "\n";
            tp.erase(it);
        }
    }

    return 0;
}