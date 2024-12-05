// week1-day5 lowerbound q1 //

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    int arr[n];

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    vector<int> v(arr, arr + n);

    while (q--) {
        int x;
        cin >> x;

        auto low = lower_bound(v.begin(), v.end(), x);
        if (low != v.end() && *low == x) {
            cout << (low - v.begin()) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}