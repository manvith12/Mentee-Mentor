#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, a;
    cin >> n >> m >> a;

    long long flagstones_length = (n + a - 1) / a;
    long long flagstones_width = (m + a - 1) / a;

    cout << flagstones_length * flagstones_width << endl;

    return 0;
}