#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int recursion(vector<int>& nums, int target, int ind) {
    if (ind == 0) {
        if (nums[0] == 0 && target == 0) return 2; // To handle zeroes in it 
        if (target - nums[0] == 0) return 1;
        if (target + nums[0] == 0) return 1;
        return 0;
    }
    int pos = recursion(nums, target - nums[ind], ind - 1);
    int neg = recursion(nums, target + nums[ind], ind - 1);
    return pos + neg;
}

// memoization
int memoization(vector<int>& nums, int target, int ind, vector<vector<int>>& dp, int sum) {
    if (target + sum < 0 || target - sum > 0) return 0;

    if (ind == 0) {
        if (nums[0] == 0 && target == 0) return 2; 
        if (target - nums[0] == 0) return 1;
        if (target + nums[0] == 0) return 1;
        return 0;
    }
    if (dp[ind][target + sum] != -1) {
        return dp[ind][target + sum];
    }
    int pos = memoization(nums, target - nums[ind], ind - 1, dp, sum);
    int neg = memoization(nums, target + nums[ind], ind - 1, dp, sum);
    return dp[ind][target + sum] = pos + neg;
} 

// tabulation
int tabulation(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > sum) return 0;

    int limit = sum;
    vector<vector<int>> dp(n, vector<int>(2 * sum + 1, 0));

    if (nums[0] == 0) {
        dp[0][limit] = 2;
    } 
    else {
        dp[0][nums[0] + limit] = 1; 
        dp[0][-nums[0] + limit] = 1; 
    }

    for (int i = 1; i < n; i++) {
        for (int t = -sum; t <= sum; t++) {
            int pos = 0, neg = 0;
            if ((t - nums[i]) + limit >= 0 && (t - nums[i]) + limit <= 2 * sum)
                pos = dp[i - 1][(t - nums[i]) + limit];
            if ((t + nums[i]) + limit >= 0 && (t + nums[i]) + limit <= 2 * sum)
                neg = dp[i - 1][(t + nums[i]) + limit];
            dp[i][t + limit] = pos + neg;
        }
    }

    return dp[n - 1][target + limit];
}

int space_optimisation (vector<int>& nums, int target) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if ((target + totalSum) % 2 != 0 || abs(target) > totalSum)
        return 0;

    int desiredSum = (target + totalSum) / 2;
    vector<int> dp(desiredSum + 1, 0);
    dp[0] = 1;

    for (int num : nums) {
        for (int sum = desiredSum; sum >= num; sum--) {
            dp[sum] += dp[sum - num];
        }
    }
    return dp[desiredSum];
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int n = nums.size();
    cout << recursion(nums, target, n - 1);
    return 0;
}