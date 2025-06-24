#include <bits/stdc++.h>
using namespace std;

int trappingrainwater (vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMax(n, nums[0]), rightMax(n, nums[n - 1]);

    for (int i = 1; i < n; i++) {
        leftMax[i] = max(nums[i], leftMax[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(nums[i], rightMax[i + 1]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (min(leftMax[i], rightMax[i]) > nums[i]) {
            res += min(leftMax[i], rightMax[i]) - nums[i];
        }
    }
    return res;
}

// We are trying to find minimum from traversal from both side, we stop when greater element is encountered
int optimal (vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int left = 0, right = n - 1, total = 0;
    int leftMax = 0, rightMax = 0;

    while (left <= right) {
        int height = min(leftMax, rightMax);
        if (nums[right] > nums[left]) {
            if (height > nums[left]){
                total += height - nums[left];
            }
            left++;
        }
        else {
            if (height > nums[right]) {
                total += height - nums[right];
            }
            right--;
        }
        leftMax = max(nums[left], leftMax);
        rightMax = max(nums[right], rightMax);
    }
    return total;
}

int main() {
    vector<int> nums = {1, 3, 5, 2, 0, 4, 10, 5, 11, 3};
    cout << trappingrainwater(nums) << endl;
    cout << optimal(nums);
    return 0;
}