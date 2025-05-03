#include <bits/stdc++.h>
using namespace std;

// Case I : all positives
int maxProduct(vector<int>& nums) {
    long long ans = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > ans) {
            ans *= 1ll * nums[i];
        }
    }
    return ans;
}

// Case II : even number of negatives
int maxProduct(vector<int>& nums) {
    long long ans = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > ans) {
            ans *= 1ll * nums[i];
        }
    }
    return ans;
}

// Case III : odd number of negatives
int maxProduct(vector<int>& nums) {
    long long ans = INT_MIN;
    long long prefix = 1, suffix = 1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        prefix *= nums[i];
        suffix *= nums[n-i-1];
        ans = max({ans, suffix, prefix});
    }
    return (int)ans;
}

// Case IV : with real numbers (pos + neg + zero)
int maxProduct(vector<int>& nums) {
    long long ans = INT_MIN;
    long long prefix = 1, suffix = 1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;
        prefix *= nums[i];
        suffix *= nums[n-i-1];
        ans = max({ans, suffix, prefix});
    }
    return (int)ans;
}

int main() {
    
    return 0;
}