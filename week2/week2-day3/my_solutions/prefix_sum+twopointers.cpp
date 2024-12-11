// week2- day3 twopointers q2
// link: https://cses.fi/problemset/task/1660/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);k
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int start = 0, end = 0;
    int sum = 0;
    int cnt = 0;

    while (end < n) {
        sum += a[end];
        end += 1;

        while (sum > x && start < end) {
            sum -= a[start];
            start += 1;
        }

        if (sum == x) {
            cnt += 1;
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}