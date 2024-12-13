#include <iostream>
#include <climits>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long n, k;
    cin >> n >> k;
    
    long long ans = 0;
    long long a[k];
    
    for (long long i = 0; i < k; i++) {
        cin >> a[i];
    }

    for (long long i = 1; i < (1 << k); i++) {
        long long x = -1;
        if (__builtin_popcount(i) & 1) {
            x = 1;
        }
        
        long long y = n;
        long long z = 1;
        
        for (long long j = 0; j < k; j++) {
            if (i >> j & 1) {
                if (z >= n / a[j] + 1) {
                    z = LLONG_MAX;
                    break;
                }
                z = z * a[j];
            }
        }
        ans += x * (y / z);
    }
    
    cout << ans;
    return 0;
}