#include <bits/stdc++.h>
using namespace std;

void merge (vector<int>& nums, int left, int mid, int right) {
    int n = nums.size();
    vector<int> res;
    int l = left, r = mid + 1;
    while (l <= mid && r <= right) {
        if (nums[left] <= nums[right]) {
            res.push_back(nums[left]);
            left++;
        }
        else {
            res.push_back(nums[right]);
            right++;
        }
    }
    while (l <= mid) {
        res.push_back(nums[l]);
        l++;
    }
    while (r <= right) {
        res.push_back(nums[r]);
        r++;
    }
    for (int i = left; i <= right; i++) {
        nums[i] = res[i - left];
    }
}
void sort (vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    sort (nums, left, mid);
    sort (nums, mid + 1, right);
    merge (nums, left, mid, right);
}
int main() {
    
    return 0;
}