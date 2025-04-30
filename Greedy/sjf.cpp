#include <bits/stdc++.h>
using namespace std;

long long SJF(vector<int>& bt) {
    // code here
    long long wt = 0, t = 0;
    int n = bt.size();
    sort(bt.begin(), bt.end());
    for (int i = 0; i < n; i++) {
        wt += t;
        t += bt[i];
    }
    return wt / n;
}

int main() {
    
    return 0;
}