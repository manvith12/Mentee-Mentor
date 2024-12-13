```cpp

// week2-day6 (distinct numbers) q1
// Link: https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000000000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;  
    bitset <MAX_VAL+1> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.set(x);
    }
    cout << s.count() << endl;




    return 0;
}
```

```cpp


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
```

```cpp

#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int flag=0;
  vector<long long> a(1024,0);
  a[0]++;
  long long result=0;
  for(auto &nx : s){

    flag^=(1<<(nx-'0'));
    result+=a[flag];
    a[flag]++;

  }
  cout << result << "\n";
  return 0;
}
```