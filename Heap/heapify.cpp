#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void heapify (vector<int>& nums, int i) {
        int n = nums.size();
        int left = 2 * i + 1, right = 2 * i + 2;
        int largest = i;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, largest);
        }
    }
    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for (int i = n/2-1; i >= 0; i--) {
            heapify(nums, i);
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 20, 30, 21, 23};
    vector<int> res = sol.minToMaxHeap(nums);
    for (int num : res) cout << num << " ";
    return 0;
}