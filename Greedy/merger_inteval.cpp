#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    int i = 0, j = 1;
    while (i < n) {
        int first = intervals[i][0];
        int second = intervals[i][1];
        while (i < n - 1 && second >= intervals[i + 1][0]) {
            second = max(intervals[i + 1][1], second);
            i++;
        }
        res.push_back({first, second});
        i++;
    }
    return res;
}

int main() {
    
    return 0;
}