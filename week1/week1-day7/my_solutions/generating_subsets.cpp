//week1-day7 , generating subsets q1

#include <iostream>
#include <vector>

using namespace std;

void gen(vector<int>& nums, vector<int>& sub, int index) {
    if (index == nums.size()) {
        cout << "-> ";
        for (int num : sub) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    gen(nums, sub, index + 1);
    sub.push_back(nums[index]);
    gen(nums, sub, index + 1);
    sub.pop_back();
}
void print(vector<int>& nums) {
    vector<int> sub;
    gen(nums, sub, 0);
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