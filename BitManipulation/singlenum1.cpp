#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}
// The above code is a solution to the problem of finding the single number in an array where every other number appears twice.

int main() {
    
    return 0;
}