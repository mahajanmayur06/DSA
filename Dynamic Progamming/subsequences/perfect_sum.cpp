#include <bits/stdc++.h>
using namespace std;

int solve (vector<int>& arr, int target, int index) {
    if (index == 0) {
        int count = 0;
        if (target == 0) count++;
        if (arr[0] == target) count++;
        return count;
    }
    int non_take = solve(arr, target, index - 1);
    int take = 0;
    if (arr[index] <= target) {
        take = solve(arr, target - arr[index], index - 1);
    }
    return take + non_take;
}

int memoization (vector<int>& arr, int target, int index, vector<vector<int>>& dp) {
    if (index == 0) {
        int count = 0;
        if (target == 0) count++;
        if (arr[0] == target) count++;
        return count;
    }
    int non_take = memoization(arr, target, index - 1, dp);
    int take = 0;
    if (arr[index] <= target) {
        take = memoization(arr, target - arr[index], index - 1, dp);
    }
    return take + non_take;
}

int tabulation (vector<int>& arr, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1; 

    for (int num : arr) {
        for (int t = target; t >= num; t--) {
            dp[t] += dp[t - num];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {5, 2, 3, 10, 6, 8};
    int target = 10;

    return 0;
}