#include <bits/stdc++.h>
using namespace std;

int solve (string& s, string& t, int i, int j) {
    if(j < 0) {
        return 1;   
    }
    if (i < 0) {
        return 0;
    }
    int count = 0;
    if (s[i] == t[j]) {
        count += solve(s, t, i - 1, j - 1);
    }
    count += solve(s, t, i - 1, j);
    return count;
}

map<pair<int, int>, int> dp;
int memoize (string& s, string& t, int i, int j) {
    if (j < 0) {
        return 1;   
    }
    if (i < 0) {
        return 0;
    }
    if (dp.count({i, j})) {
        return dp[{i, j}];
    }
    int count = 0;
    if (s[i] == t[j]) {
        count += memoize(s, t, i - 1, j - 1);
    }
    count += memoize(s, t, i - 1, j);
    return dp[{i, j}] = count;
}

int stringMatching (string& s, string& t) {
    int n = s.size(), m = t.size();
    vector<double> dp (m + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }
    return (int)dp[m];
}

int main() {
    
    return 0;
}