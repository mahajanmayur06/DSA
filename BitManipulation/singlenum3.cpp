#include <bits/stdc++.h>
using namespace std;


// This approach follows the concept of buckets, after finding the xor of all elements, there would be atleast one set bit in the resulting element. We will use right most set bit to divide the elements into two buckets. as it is simple to calculate it using the formula : (number & (number - 1)) ^ number.
// The elements in each bucket will have a different value for the set bit. Hence, two different numbers that are required
// The time complexity of this approach is O(n) and the space complexity is O(1).
vector<int> singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
        ans ^= num;  // ans = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
    int num = INT_MIN;
    if (ans > INT_MIN) {
        num = (ans & (ans - 1)) ^ ans;
    }
    int b1 = 0, b2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (num & nums[i]) {
            b1 ^= nums[i];
        }
        else {
            b2 ^= nums[i];
        }
    }
    return {b1, b2};
}

int main() {
    
    return 0;
}