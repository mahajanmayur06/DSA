#include <bits/stdc++.h>
using namespace std;


// Brute force
int subarraySum(vector<int>& nums, int k) {
    int len = 0;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum == k) len++;
        }
    }
    return len;
}

// Better works for pos and (post + neg) numbers
int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    unordered_map<int, int> mp;
    mp[0]= 1;
    int prefixSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        int x = prefixSum - k;
        count += mp[x];
        mp[prefixSum]++;
    }
    return count;
}

// Better works only for pos numbers
int subarraySum(vector<int>& nums, int k) {
    int l = 0, r = 0, sum = 0, count = 0;
    int n = nums.size();
    
    while (r < n) {
        sum += nums[r];
        while (sum > k) {
            sum -= nums[l];
            l++;
        }
        if (sum == k) {
            count++;
        }
        r++;
    }
    
    return count;
}
int main() {
    
    return 0;
}