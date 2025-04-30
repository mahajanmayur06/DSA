#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<pair<double, int>> ratio(n);
    
    for (int i = 0; i < n; i++) {
        double v = static_cast<double>(val[i]);
        ratio[i] = {v / wt[i], i};
    }

    sort(ratio.begin(), ratio.end(), [](pair<double, int>& a, pair<double, int>& b) {
        return a.first > b.first; 
    });

    int k = 0;
    double res = 0;
    for (int i = 0; i < n && k < capacity; i++) {
        double r = ratio[i].first;
        int ind = ratio[i].second;
        int v = val[ind], w = wt[ind];
        int diff = capacity - k;
        if (diff >= w) {
            res += v;
            k += w;
        } 
        else {
            res += (double)v * (double)diff / w;
            break;
        }
    }
    return res;
}

int main() {
    
    return 0;
}