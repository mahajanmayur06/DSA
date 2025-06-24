#include <bits/stdc++.h>
using namespace std;

// The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
vector<int> findPSE(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] >= nums[i])
            s.pop();
        if (!s.empty())
            res[i] = s.top();
        s.push(i);
    }
    return res;
}

vector<int> findNSE(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] > nums[i])
            s.pop();
        if (!s.empty())
            res[i] = s.top();
        s.push(i);
    }
    return res;
}

vector<int> findPGE(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] <= nums[i])
            s.pop();
        if (!s.empty())
            res[i] = s.top();
        s.push(i);
    }
    return res;
}

vector<int> findNGE(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] < nums[i])
            s.pop();
        if (!s.empty())
            res[i] = s.top();
        s.push(i);
    }
    return res;
}

long long findMinSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse = findPSE(nums), nse = findNSE(nums);
    int mod = 1e9 + 7;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        total += nums[i] * left * right;
    }
    return total;
}

long long findMaxSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge = findPGE(nums), nge = findNGE(nums);
    int mod = 1e9 + 7;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pge[i];
        long long right = nge[i] - i;
        total += nums[i] * left * right;
    }
    return total;
}

int subArrayRanges (vector<int>& nums) {
    return findMaxSum(nums) - findMinSum(nums);
}

int main() {
    vector<int> nums = {4,-2,-3,4,1};
    cout << subArrayRanges(nums);
    return 0;
}