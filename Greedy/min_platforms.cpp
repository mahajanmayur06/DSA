#include <bits/stdc++.h>
using namespace std;

// Using priority queue
int findPlatform(vector<int>& arr, vector<int>& dep) {
    // Your code here
    int n = arr.size();
    
    vector<vector<int>> time;
    for (int i = 0; i < n; i++) {
        time.push_back({arr[i], dep[i]});
    }
    sort(time.begin(), time.end(), [](vector<int>&a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    });
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int arv = time[i][0], dep = time[i][1];
        
        while (!pq.empty() && pq.top() < arv) {
            pq.pop();
        }
        
        pq.push(dep);
        int size = pq.size();
        count = max(count, size);
    }
    
    return count;
}

// Using line sweep
int findPlatform(vector<int>& arr, vector<int>& dep) {
    // Your code here
    int n = arr.size();
    
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int count = 1;
    int plt = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plt++;
            i++;
        }
        else {
            plt--;
            j++;
        }
        count = max(count, plt);
    }
    return count;
}


int main() {
    
    return 0;
}