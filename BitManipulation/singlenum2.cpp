#include <bits/stdc++.h>
using namespace std;

// this approach follows couting number of set bits at every (0 to 31)th position, if number is appearing exactly 3 times, then remainder of count with 3 is always going to be 0, if not, then at that position it is sure, that there is set bit.
// time : O(32*N)
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if ((nums[j] >> i) & 1) {
                count++;
            }
        }
        if (count % 3 != 0) {
            res |= (1 << i);
        }
    }
    return res;
}

// sorting and using two pointer approach takes (N*lon(N) + N/3) time

// concepts of bucket
// time O(n)
int singleNumber (vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main() {
    
    return 0;
}