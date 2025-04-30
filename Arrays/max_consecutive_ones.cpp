#include <bits/stdc++.h>
using namespace std;

// optimal
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxCount = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            count = 0;
        }
        else {
            count++;
        }
        maxCount = max(count, maxCount);
    }
    return maxCount;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, i = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] == 0) {
            continue;
        }
        int last = i;
        while (i < n && nums[i] == 1) {
            i++;
        }
        maxCount = max(maxCount, i - last);
        i++;
    }
    return maxCount;
}

int main() {
    
    return 0;
}