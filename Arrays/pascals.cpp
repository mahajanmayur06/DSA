#include <bits/stdc++.h>
using namespace std;

// To get the value at rth row and cth column
// time O(r) space O(1)
int pascalValue(int r, int c) {
    // return (n-1)C(r-1);
    r--;
    c--;
    int res = 1;
    for (int i = 1; i <= c; i++) {
        res *= (r - i + 1);
        res /= i;
    }
    return res;
}

// To get rth row of pascal triangle
// time O(r) space O(1)
vector<int> pascalRow(int r) {
    vector<int> res(r, 1);
    for (int i = 1; i < r; i++) {
        res[i] = res[i - 1] * (r - i) / i;
    }
    return res;
}

// To get pascal triangle
// Brute force -> O(n * n * r) using pascalValue

// Better approach
vector<vector<int>> pascalTree(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++) {
        vector<int> temp(i + 1, 1);
        for (int j = 0; j <= i; j++) {
            if (i > 0 && j > 0 && j < i) {
                temp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        res.push_back(temp);
    }
    return res;
}

// Optimal
// time O(n^2) space O(1)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 1; i <= numRows; i++) {
        res.push_back(pascalRow(i));
    }
    return res;
}
int main() {
    
    return 0;
}