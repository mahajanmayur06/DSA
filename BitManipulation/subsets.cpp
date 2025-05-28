#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    int size = 1 << n;
    for (int num = 0; num < size; num++) {
        vector<int> list;
        for (int j = 0; j < n; j++) {
            if ((num >> j) & 1) {
                list.push_back(nums[j]);
            }
        }
        res.push_back(list);
    }
    return res;
}

int main() {
    
    return 0;
}