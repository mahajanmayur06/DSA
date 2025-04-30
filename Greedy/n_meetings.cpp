#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    // Your code here
    vector<vector<int>> mat;
    int n = start.size();
    for (int i = 0; i < n; i++) {
        mat.push_back({start[i], end[i]});
    }
    sort(mat.begin(), mat.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1]; 
    });
    
    int count = 0;
    int e = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][0] > e) {
            count++;
            e = mat[i][1];
        }
    }
    return count;
}

int main() {
    
    return 0;
}