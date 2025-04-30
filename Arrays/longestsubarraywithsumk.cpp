#include <bits/stdc++.h>
using namespace std;


// Brute force
int subarraySum(vector<int>& nums, int k) {
    int len = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k) len = max(len, j - i + 1);
        }
    }
    return len;
}

// Better works for pos and (post + neg) numbers
int maxSubArrayLen(vector<int>& nums, int k) {
    int maxLen = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int prefixSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        int x = prefixSum - k;
        if (mp.count(x)) {
            maxLen = max(maxLen, i - mp[x]);
        }
        if (!mp.count(prefixSum)) {
            mp[prefixSum] = i;
        }
    }
    return maxLen;
}


// Better works only for pos numbers
int maxSubArrayLen(vector<int>& nums, int k) {
    int l = 0, r = 0, sum = 0, maxLen = 0;
    int n = nums.size();

    while (r < n) {
        sum += nums[r];
        while (sum > k) {
            sum -= nums[l];
            l++;
        }
        if (sum == k) {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }

    return maxLen;
}

int main() {
    
    return 0;
}