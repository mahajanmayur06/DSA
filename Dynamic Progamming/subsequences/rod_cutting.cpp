#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve (vector<int>& prices, int i, int n) {
    if (i == 0) {
        if (i <= n) {
            return prices[i] * n;
        }
    }
    int take = 0, non_take = 0;
    non_take = solve(prices, i - 1, n);
    int rodLength = i + 1;
    if (rodLength <= n) {
        take = prices[i] + solve(prices, i, n - rodLength);
    }
    return max(take, non_take);
}

int tabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int rodLength = 0; rodLength <= n; rodLength++) {
        dp[0][rodLength] = rodLength * prices[0];
    }

    for (int i = 1; i < n; i++) {
        for (int rodLength = 1; rodLength <= n; rodLength++) {
            int take = 0, non_take = 0;
            non_take = dp[i - 1][rodLength];
            if (rodLength >= i + 1) {
                take = prices[i] + dp[i][rodLength - (i + 1)];
            }
            dp[i][rodLength] = max(take, non_take);
        }
    }

    return dp[n - 1][n];
}

int space_optimised (vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n + 1, 0);

    for (int rodLength = 0; rodLength <= n; rodLength++) {
        dp[rodLength] = rodLength * prices[0];
    }

    for (int i = 1; i < n; i++) {
        for (int rodLength = 1; rodLength <= n; rodLength++) {
            int take = 0, non_take = 0;
            non_take = dp[rodLength];
            if (rodLength >= i + 1) {
                take = prices[i] + dp[rodLength - (i + 1)];
            }
            dp[rodLength] = max(take, non_take);
        }
    }

    return dp[n];
}

int main()
{
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20}, prices1 = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    cout << solve(prices, n - 1, n);
    cout << solve(prices1, n - 1, n);
    return 0;
}