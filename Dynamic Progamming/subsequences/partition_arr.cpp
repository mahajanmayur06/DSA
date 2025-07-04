#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// only positives
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

int main()
{
    vector<int> nums = {1, 2, 10, 41};
    int d = 5;
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int modified_target = totalSum  - d; // /2
    if (modified_target % 2 == 0 && modified_target >= 0) {
        // call subset sum with modified target
        modified_target /= 2;
        cout << tabulation(nums, modified_target);
    }
    return 0;
}