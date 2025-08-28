#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  A B C D
// 0 1 2 3 4
//   i     j

// partition on basis of k
int recursion (vector<int>& nums, int i, int j) {
    if (i == j) {
        return 0;
    }
    int res = 1e9;
    for (int k = i; k < j; k++) {
        int cost = nums[i - 1] * nums[k] * nums[j] + recursion(nums, i, k) + recursion(nums, k + 1, j);
        res = min(res, cost);
    }
    return res;
}

// tabulation
int minimumMatrixMultiplication (vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp (n ,vector<int> (n, INT_MAX));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j < n; j++) {
            for (int k = i; k < j; k++) {
                int cost = nums[i - 1] * nums[k] * nums[j] + dp[i][k] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];    
}

int main() {
    vector<int> nums = {3,7,4,5};
    // vector<int> nums = {1,3,1,4,1,5};
    int n = nums.size();
    cout << recursion(nums, 1, n - 1);
    // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    // cout << ans << endl;
    // cout << memoization(nums, 1, n - 1, dp) << endl;
    // cout << tabulation(nums);
    return 0;
}