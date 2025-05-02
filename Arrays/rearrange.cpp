#include <bits/stdc++.h>
using namespace std;

// brute force time O(n + n/2) space O(n) -> O(pos+neg)
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        nums[i] > 0 ? pos.push_back(nums[i]) : neg.push_back(nums[i]);
    }
    int i = 0;
    for (int k = 0; k < n / 2; k++) {
        nums[2 * i] = pos[k];
        nums[2 * i + 1] = neg[k];
        i++;
    }
    return nums;
}

// better O(n) time O(n) space
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;
    vector<int> res(n);
    for (int k = 0; k < n; k++) {
        if (nums[k] > 0) {
            res[i] = nums[k];
            i += 2;
        }
        else {
            res[j] = nums[k];
            j += 2;
        }
    }
    return res;
}

int main() {
    
    return 0;
}