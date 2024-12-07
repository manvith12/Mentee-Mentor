// week1-day7 permutations q1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<int>& nums, int start, int end) {
    if (start == end) {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= end; ++i) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, end);
        swap(nums[start], nums[i]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    permute(nums, 0, n - 1);

    return 0;
}