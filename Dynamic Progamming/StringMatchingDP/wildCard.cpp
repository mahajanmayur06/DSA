#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> dp;
bool solve(string& s, string& p, int i, int j) {
    if (i < 0 && j < 0) {
        return true;
    }
    if (j < 0 && i >= 0) {
        return false;
    }
    if (i < 0 && j >= 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true; 
    }
    if (dp.count({i, j})) {
        return dp[{i, j}];
    }
    if (s[i] == p[j] || p[j] == '?') {
        return dp[{i, j}] = solve(s, p, i - 1, j - 1);
    }
    if (p[j] == '*') {
        return dp[{i, j}] = solve(s, p, i - 1, j) || solve(s, p, i, j - 1);
    }
    return dp[{i, j}] = false;
}

int main() {
    
    return 0;
}