#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());
    int len = 1;
    int count = 1;
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] - nums[i-1] == 1){
            count++;
        }
        else if (nums[i] == nums[i-1]) {
            continue;
        }
        else {
            len = max(len, count);
            count = 1;
        }
    }
    len = max(len, count);
    return len;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int count = 0;
    for (auto& num : s) {
        if (!s.count(num - 1)) {
            int c = 0;
            int n = num;
            while (s.count(n)) {
                c++;
                n++;
            }
            count = max(c, count);
        }
    }
    return count;
}


int main() {
    
    return 0;
}