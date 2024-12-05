// week1-day5 , lowerbound q2, concerts✨ //
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
        int max_p;
        cin >> max_p;

        auto it = tp.lower_bound(max_p);
        if (it == tp.end() || *it > max_p) {
            if (it == tp.begin()) {
                cout << -1 << endl;
            } else {
                --it;
                cout << *it << endl;
                tp.erase(it);
            }
        } else {
            cout << *it << endl;
            tp.erase(it);
        }
    }

    return 0;
}
