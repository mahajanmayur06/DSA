#include <bits/stdc++.h>
using namespace std;

vector<int> findNSE (vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top();
        }
        s.push(i);
    }
    return res;
}

vector<int> findPSE (vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] >= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            res[i] = s.top();
        }
        s.push(i);
    }
    return res;
}

int largestAreaInHistogram (vector<int>& height) {
    int n = height.size();
    vector<int> nse = findNSE(height), pse = findPSE(height);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        res = max(res, height[i] * width);
    }
    return res;
}

// Intution: when at index i, traverse back to make i as next smallest element so that width can be computed without precomputing
// TC : O(2N), SC = O(N)
int optimisedLargestAreaInHistogram (vector<int>& height) {
    int n = height.size();
    stack <int> s;
    int res = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && height[s.top()] > height[i]) {
            int index = s.top();
            s.pop();
            int pse = s.empty() ? -1 : s.top();
            int width = i - pse - 1;
            res = max(res, width * height[index]);
        }
        s.push(i);
    }
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        int pse = s.empty() ? -1 : s.top();
        int width = n - pse - 1;
        res = max(res, height[index] * width);
    }
    return res;
}

int main() {
    vector<int> heights = {3, 2, 10, 11, 5, 10, 6, 3};
    cout << largestAreaInHistogram(heights) << endl << optimisedLargestAreaInHistogram(heights);
    return 0;
}