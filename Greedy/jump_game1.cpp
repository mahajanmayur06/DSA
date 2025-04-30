#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        if (i > maxi && nums[i] == 0) {
            return false;
        }
        maxi = max(maxi, i + nums[i]);
        if (maxi >= n - 1) {
            return true;
        }
    }
    return true;
}

int main() {
    
    return 0;
}