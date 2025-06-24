#include <bits/stdc++.h>
using namespace std;

vector<int> naive (vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i <= n - k; i++) {
        int maxi = nums[i];
        for (int j = i; j < i + k - 1; i++) {
            maxi = max(maxi, nums[j]);
        }
        res.push_back(maxi);
    }
    return res;
}

// considering insetion of eleements in deque, permits me to extract maximum element for required window, if first element is exceeding window length k, remove it from front
// TC : O(2N)
vector<int> slidingWindowMaximum (vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && (dq.front() <= i - k || nums[dq.back()] <= nums[i])) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

int main() {
    
    return 0;
}