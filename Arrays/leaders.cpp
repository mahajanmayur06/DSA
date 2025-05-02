#include <bits/stdc++.h>
using namespace std;

// brute force
// time complexity O(n^2) space complexity O(1)
vector<int> leaders(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] >= nums[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            res.push_back(nums[i]);
        }
    }
    return res;
}


// Better 
// time complexity O(n) space complexity O(n)
vector<int> leaders (vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    vector<int> maxRight(n);
    maxRight[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], nums[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] >= maxRight[i + 1]) {
            res.push_back(nums[i]);
        }
    }
    res.push_back(nums[n - 1]);
    return res;
}

// Better 
// time complexity O(n) space complexity O(n) + O(ans/2)
vector<int> leaders (vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    int maxRight = nums[n - 1];
    res.push_back(maxRight);
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] >= maxRight) {
            res.push_back(nums[i]);
        }
        maxRight = max(maxRight, nums[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

// Optimal
// time complexity O(2n) space complexity O(n)
vector<int> leaders (vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    res.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        while (!res.empty() && res.back() < nums[i]) {
            res.pop_back();
        }
        res.push_back(nums[i]);
    }
    return res;
}

int main() {
    
    return 0;
}