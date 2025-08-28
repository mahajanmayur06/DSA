#include <bits/stdc++.h>
using namespace std;

int solve (vector<int>& nums, int k, int i) {
    int n = nums.size();
    if (i == n) {
        return 0;
    }
    int ex, inc = 0;
    ex = nums[i] | solve (nums, k, i + 1);
    if (k > 0) {
        inc = 2 * nums[i] | solve(nums, k - 1, i);
    }
    return max(ex, inc);
}

int main() {
    int k = 0;
    vector<int> nums = {1, 5, 19};
    cout << solve(nums, k, 0);
    return 0;
}