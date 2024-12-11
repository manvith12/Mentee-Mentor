// week2-day3 twopointers q1
// link: https://cses.fi/problemset/task/1640

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }
    
    
    sort(a.begin(), a.end());
    
    int i = 0, j = n - 1;
    while (i < j) {
        int sum = a[i].first + a[j].first;
        if (sum == x) {
            cout << a[i].second << " " << a[j].second << "\n";
            return 0;
        } else if (sum < x) {
            ++i;
        } else {
            --j;
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}
