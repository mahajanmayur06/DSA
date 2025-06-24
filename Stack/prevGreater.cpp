#include <bits/stdc++.h>
using namespace std;

vector<int> findPGE (vector<int>& nums) {
    int n = nums.size();
    vector<int> pge (n, -1);
    stack<int> s;

    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() < nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            pge[i] = s.top();
        }
        s.push(nums[i]);
    }
    return pge;
}

int main() {
    vector<int> nums = {12, 20, 10, 100, 23, 80, 32};
    vector<int> res = findPGE(nums);
    for (int num : res) cout << num << " ";
    return 0;
}