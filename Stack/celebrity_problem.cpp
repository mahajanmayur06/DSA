#include <bits/stdc++.h>
using namespace std;

int findCelebrity (vector<vector<int>>& mat) {
    int n = mat.size();
    vector<int> indegree(n), outdegree(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                outdegree[i]++;
                indegree[j]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            return i;
        }
    }
    return -1;
}

int celebrityProblem (vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if (mat[i][j]) {
            s.push(j);
        }
        else {
            s.push(i);
        }
    }
    int celeb = s.top();
    s.pop();

    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            if (!mat[i][celeb] || mat[celeb][i]) {
                return -1;
            }
        }
    }
    return celeb;
}

int main() {
    
    return 0;
}