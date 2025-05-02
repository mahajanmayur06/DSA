#include <bits/stdc++.h>
using namespace std;

// brute force O(n^4)
// using set and converting set to vector of answers
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    res.assign(s.begin(), s.end());
    return res;
}

// Better approach
// time O(n^3 log m) space O(2*no of qudruplets) one for uniques and answer + O(n)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> seen;
            for (int k = j + 1; k < n; k++) {
                long long sum = nums[i] + nums[j] + nums[k];
                long long fourth = target - sum;
                if (seen.count(fourth)) {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                seen.insert(nums[k]);
            }
        }
    }
    res.assign(s.begin(), s.end());
    return res;
}

// Optimal approach using hash
// sorting here saves to store it in set, that ensures no duplicates
// time O(n^3) space O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = n - 1;
            while (left < right) {
                long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
    }
    return res;
}


int main() {
    
    return 0;
}