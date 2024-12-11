// week2-day3 prefix sum q2 
// link: https://cses.fi/problemset/task/1662

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

 
    unordered_map<int, int> freq;
    freq[0] = 1; 

    long long prefix = 0;
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        prefix += arr[i];

       
        int rem = ((prefix % n) + n) % n;

    
        count += freq[rem];

        
        freq[rem]++;
    }

    cout << count << endl;
    return 0;
}
