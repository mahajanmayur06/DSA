#include <bits/stdc++.h>
using namespace std;

// Moore's voting algorithm
// time O(n) space O(1)
int majorityElement(vector<int>& nums) {
    int count = 0, n = nums.size();
    int num = -1;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            num = nums[i];
            count++;
        }
        else if (num == nums[i]) {
            count++;
        }
        else {
            count--;
        }
    }
    return num;
}

int main() {
    
    return 0;
}