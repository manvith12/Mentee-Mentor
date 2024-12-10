#include <bits/stdc++.h>
using namespace std;

bool square(long long x) {
    long long s = sqrt(x);
    return (s * s == x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long sum = accumulate(a.begin(), a.end(), 0LL); // Use 0LL to ensure long long sum
        if (square(sum)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}