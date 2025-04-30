#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0){ 
            swap(nums[i], nums[k]);
            k++;
        }
    }
}

int main()
{
    
    return 0;
}