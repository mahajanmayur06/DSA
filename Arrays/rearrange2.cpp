#include <bits/stdc++.h>
using namespace std;

// time complexity O(n) space complexity O(n)
// O(n) + O(min(pos, neg)) + O(leftovers) = O(n) + O(n) + O(n) = O(2n)
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;

    for (int i = 0; i < n; i++) {
        nums[i] > 0 ? pos.push_back(nums[i]) : neg.push_back(nums[i]);
    }

    int p = pos.size(), ne = neg.size();
    int i = 0, j = 0, k = 0;

    while (i < p && j < ne) {
        nums[k++] = pos[i++];
        nums[k++] = neg[j++];
    }

    while (i < p) nums[k++] = pos[i++];
    while (j < ne) nums[k++] = neg[j++];

    return nums;
}

int main() {
    
    return 0;
}