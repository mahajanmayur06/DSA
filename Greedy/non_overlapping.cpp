#include <bits/stdc++.h>
using namespace std;    

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });
    int count = 0;
    int end = intervals[0][1];
    for (int i = 1; i < n; i++) {
        if (end > intervals[i][0]) {
            count++;
        }
        else{
            end = intervals[i][1];
        } 
    }
    return count;
}

int main() {
    
    return 0;
}