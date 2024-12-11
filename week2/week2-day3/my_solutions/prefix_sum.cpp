// week2-day3 prefix_sum q1
// link: https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    vector<long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<long long> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        if (l == 1)
        {
            cout << prefix_sum[r-1] << "\n";
        }
        else
        {
            cout << prefix_sum[r-1] - prefix_sum[l-2] << "\n";
        }
    }

    
    
    return 0;
}