#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]); 
}

void unionSets(int u, int v) {
    parent[u] = v;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = profit.size();
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        arr.push_back({profit[i], deadline[i]});
    }

    sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    });

    int maxDeadline = *max_element(deadline.begin(), deadline.end());
    parent.resize(maxDeadline + 1);

    for (int i = 0; i <= maxDeadline; i++) {
        parent[i] = i;
    }

    int totalProfit = 0, countJobs = 0;

    for (auto job : arr) {
        int availableSlot = find(job.second);
        if (availableSlot > 0) {
            totalProfit += job.first;
            countJobs++;

            unionSets(availableSlot, availableSlot - 1);
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    
    return 0;
}