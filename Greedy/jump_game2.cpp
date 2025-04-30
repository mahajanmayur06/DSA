#include <bits/stdc++.h>
using namespace std;

int countJump (vector<int>& nums) {
    int n = nums.size();
    int far = 0;
    int count = 0;
    int l = 0, r = 0;
    
    for (int i = 0; i < n; i++) {
        for (int i = l ; i <= r; i++) {
            far = max(far, i + nums[i]);
        }
        l = r + 1;
        r = far;
        count++;
    }
    return count;
}

int main() {
    
    return 0;
}