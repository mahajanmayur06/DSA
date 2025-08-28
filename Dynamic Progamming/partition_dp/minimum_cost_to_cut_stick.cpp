#include <bits/stdc++.h>
using namespace std;

long long solve (vector<int>& nums, int i, int j) {
    if (i > j) {
        return 0;
    }
    long long mincosts = INT_MAX;
    for (int k = i; k <= j; k++) {
        long long cost = nums[j + 1] - nums[i - 1] + solve(nums, i, k - 1) + solve(nums, k + 1, j);
        mincosts = min(mincosts, cost);
    }
    return mincosts;
}

map<pair<int, int>, long long> dp;
long long solve (vector<int>& nums, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (dp.count({i, j})) {
        return dp[{i, j}];
    }
    long long mincosts = INT_MAX;
    for (int k = i; k <= j; k++) {
        long long cost = nums[j + 1] - nums[i - 1] + solve(nums, i, k - 1) + solve(nums, k + 1, j);
        mincosts = min(mincosts, cost);
    }
    return dp[{i, j}] = mincosts;
}

int minCost(int n, vector<int>& cuts) {
    int size = cuts.size();
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    vector<vector<long long>> dp (size + 2, vector<long long> (size + 2, 0));
    for (int i = size; i >= 1; i--) {
        for (int j = 1; j <= size; j++) {
            if (i > j) {
                continue;
            }
            long long mincosts = LLONG_MAX;
            for (int k = i; k <= j; k++) {
                mincosts = min(mincosts, 1ll * cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
            }
            dp[i][j] = mincosts;
        }
    }
    return dp[1][size];
}

int main() {
    vector<int> cuts = {};
    int n;
    int size = cuts.size();
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    return solve(cuts, 1, size);
    return 0;
}