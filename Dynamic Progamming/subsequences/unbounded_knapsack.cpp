#include <bits/stdc++.h>
using namespace std;

int solve (vector<int>& val, vector<int>& wt, int capacity, int i) {
    if (i == 0) {
        if (wt[0] <= capacity) {
            return (capacity / wt[0]) * val[0];
        }
        return 0;
    }
    int take = 0, non_take = 0;
    non_take = solve(val, wt, capacity, i - 1);
    if (wt[i] <= capacity) {
        take = val[i] + solve (val, wt, capacity - wt[i], i);
    }
    return max(take, non_take);
}

int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    return solve(val, wt, capacity, val.size() - 1);
}

int memoization (vector<int>& val, vector<int>& wt, int capacity, int i, vector<vector<int>>& dp) {
    if (i == 0) {
        if (wt[0] <= capacity) {
            return (capacity / wt[0]) * val[0];
        }
        return 0;
    }
    if (dp[i][capacity] != -1) {
        return dp[i][capacity];
    }
    int take = 0, non_take = 0;
    non_take = memoization(val, wt, capacity, i - 1, dp);
    if (wt[i] <= capacity) {
        take = val[i] + memoization (val, wt, capacity - wt[i], i, dp);
    }
    return dp[i][capacity] = max(take, non_take);
}

int knapsack2 (vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<vector<int>> dp(n, vector<int> (capacity + 1, -1));
    return memoization(val, wt, capacity, n - 1, dp);
}

int tabulation (vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<vector<int>> dp (n, vector<int> (capacity + 1));
    for (int i = 0; i <= capacity; i++) {
        dp[0][i] = val[0] * (i / wt[0]);
    }

    for (int i = 1; i < n; i++) {
        for (int cap = 0; cap <= capacity; cap++) {
            int take = 0, non_take = 0;
            non_take = dp[i - 1][cap];
            if (cap >= wt[i]) {
                take = val[i] + dp[i][cap - wt[i]];
            }
            dp[i][cap] = max(take, non_take);
        }
    }
    return dp[n - 1][capacity];
}

int space_optimisation (vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<int> dp(capacity + 1);

    for (int i = 0; i <= capacity; i++) {
        dp[i] = val[0] * (i / wt[0]);
    }

    for (int i = 1; i < n; i++) {
        for (int cap = 0; cap <= capacity; cap++) {
            int take = 0, non_take = 0;
            non_take = dp[cap];
            if (cap >= wt[i]) {
                take = val[i] + dp[cap - wt[i]];
            }
            dp[cap] = max(take, non_take);
        }
    }
    return dp[capacity];
}

int main() {
    
    return 0;
}