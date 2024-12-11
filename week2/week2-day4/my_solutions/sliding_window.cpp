//week2-day4 sliding_window q1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; ++i) {
       
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }

        
        dq.push_back(i);

        
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}