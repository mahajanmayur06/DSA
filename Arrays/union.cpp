#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Your code here
    map <int, int> freq;
    vector <int > res;
    for (int i = 0; i < a.size(); i++)
        freq[a[i]]++;
    for (int i = 0; i < b.size(); i++)
        freq[b[i]]++;
    for (auto & it: freq)
        res.push_back(it.first);
    return res;
    // return vector with correct order of elements
}

// O(n + m) time
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Your code here
    vector<int> res;
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (res.size() == 0 || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        }
        else {
            if (res.size() == 0 || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        }
    }
    
    while (i < n) {
        if (res.back() != a[i]) {
            res.push_back(a[i]);
        }
        i++;
    }
    while (j < m) {
        if (res.back() != b[j]) {
            res.push_back(b[j]);
        }
        j++;
    }
    return res;
    // return vector with correct order of elements
}

int main() {
    
    return 0;
}