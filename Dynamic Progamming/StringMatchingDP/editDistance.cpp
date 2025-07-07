#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp;
int solve (string& s, string &t, int i, int j) {
    if (i < 0) {
        return j + 1;
    }
    if (j < 0) {
        return i + 1;
    }
    if (dp.count({i, j})) {
        return dp[{i, j}];
    }
    if (s[i] == t[j]) {
        return solve (s, t, i - 1, j - 1);
    }
    return dp[{i, j}] = min({1 + solve (s, t, i, j - 1), // insert
    1 + solve (s, t, i - 1, j), // delete
    1 + solve (s, t, i - 1, j - 1)}); // replace
}
    
int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[n][m];
}
int main() {
    
    return 0;
}