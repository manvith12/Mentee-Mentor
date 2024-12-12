#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        map<long long, long long> m;
        long long s = 0;
        m[0] = 1;
        bool found = false;
        for(int i = 0; i < n; ++i) {
            a[i] *= ((i % 2) ? -1 : 1);
            s += a[i];
            if(m[s]) {
                cout << "YES\n";
                found = true;
                break;
            }
            ++m[s];
        }
        if (!found) cout << "NO\n";
    }
}
