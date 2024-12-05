// week1-day5 upperbound q3//

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

        auto up = upper_bound(v.begin(), v.end(), x);
        if (up != v.end()) {
            cout << (up - v.begin()-1) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}