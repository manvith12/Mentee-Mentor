// week1-day7 permutations q2 , using STL functions

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    permute(nums);

    return 0;
}