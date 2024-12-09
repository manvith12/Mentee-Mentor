#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> occ(26);
        for (int i=0; i<n; i++)
            occ[s[i] - 'a'] += 1;
        pair<pair<int,char>,int> low, high;
        low = high = {{occ[s[0] - 'a'], s[0]}, 0};
        for (int i=1; i<n; i++) {
            low = min(low, {{occ[s[i] - 'a'], s[i]}, i});
            high = max(high, {{occ[s[i] - 'a'], s[i]}, i});
        }
        s[low.second] = s[high.second];
        cout << s << "\n";
    }
  return 0;
}