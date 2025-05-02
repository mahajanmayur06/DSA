#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum = 0;
    int start = 0, end = 0, length = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > maxSum) {
            end = i;
            length = end - start + 1;
            maxSum = sum;
        }
        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
    }
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    return maxSum;
}

int main() {
    
    return 0;
}