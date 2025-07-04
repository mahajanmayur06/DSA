#include <bits/stdc++.h>
using namespace std;

bool solve (vector<int>& nums, int sum, int ind) {
    if (sum == 0) {
        return 1;
    }
    if (ind == 0) {
        return nums[0] == sum;
    }
    bool include = false, exclude = false;
    if (nums[ind] <= sum) {
        include = solve(nums, sum - nums[ind], ind - 1);
    }
    exclude = solve(nums, sum, ind - 1);
    return exclude || include;
}

map<pair<int, int>, bool> dp;
bool memoize (vector<int>& arr, int ind, int sum) {
    if (sum == 0) {
        return true;
    }
    if (ind == 0) {
        return arr[ind] == sum;
    }
    if (dp.count({sum, ind})) {
        return dp[{sum, ind}];
    }
    bool include = false, exclude = memoize(arr, ind - 1, sum);
    if (arr[ind] <= sum) {
        include = memoize(arr, ind - 1, sum - arr[ind]);
    }
    return dp[{sum, ind}] = include || exclude;
}

int tabulation (vector<int>& nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp (n, vector<int> (sum + 1));
    for (int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    dp[0][nums[0]] = 1;
    for (int i = 1; i < n; i++) {
        for (int s = 0; s <= sum; s++) {
            bool ex = 0, in = 0;
            if (nums[i] <= s) {
                in = dp[i - 1][s - nums[i]];
            }
            dp[i][s] = dp[i - 1][s] || in;
        }
    }
    return dp[n - 1][sum];
}

int space_optimise (vector<int>& nums, int sum) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int t = target; t >= nums[i]; t--) {
            dp[t] = dp[t] || dp[t - nums[i]];
        }
    }

    return dp[target];
}


int main() {
    vector<int> arr = {1, 2, 5, 10, 5};
    int n = arr.size();
    int target1 = 15;
    int target2 = 4;
    cout << boolalpha << solve(arr, target1, n - 1) << endl << boolalpha << solve(arr, target2, n - 1) << endl << tabulation(arr, 4);
    return 0;
}