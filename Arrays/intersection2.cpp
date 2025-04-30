#include <bits/stdc++.h>
using namespace std;

// O(nlogn + mlogm) time solution
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    vector<int> res;
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            res.push_back(nums2[j]);
            i++;
            j++;
        }
    }
    return res;
}


// O(n) space, O(n + m) solution
// duplicates are allowed
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    unordered_map<int, int> seen;
    vector<int> res;
    for (int num : nums1) {
        seen[num]++;
    }
    for (int num : nums2) {
        if (seen[num] > 0) {
            seen[num]--;
            res.push_back(num);
        }
    }
    return res;
}

int main() {
    
    return 0;
}