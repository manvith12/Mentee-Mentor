//week1-day7 , generating subsets q2

#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& nums) {
    int n = nums.size();
    int total = 1 << n;

    for (int i = 0; i < total; ++i) {
        vector<int> sub;
        for (int i = 0; i < n; ++i) {
            if (i & (1 << i)) {
                sub.push_back(nums[i]);
            }
        }
        for (int num : sub) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void print(vector<int>& nums) {
    gen(nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    print(nums);

    return 0;
}