#include <bits/stdc++.h>
using namespace std;

int largestArea (vector<int>& height) {
    int n = height.size();
    stack <int> s;
    int res = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && height[s.top()] > height[i]) {
            int index = s.top();
            s.pop();
            int pse = s.empty() ? -1 : s.top();
            int width = i - pse - 1;
            res = max(res, width * height[index]);
        }
        s.push(i);
    }
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        int pse = s.empty() ? -1 : s.top();
        int width = n - pse - 1;
        res = max(res, height[index] * width);
    }
    return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp (n, vector<int> (m, 0));
    for (int i = 0; i < m; i++) {
        dp[0][i] = matrix[0][i] - '0';
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] += 1 + dp[i - 1][j];
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, largestArea(dp[i]));
    }

    return res;
}

int main() {
    
    return 0;
}