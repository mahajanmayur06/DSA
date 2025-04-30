#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force
void sortColrs (vector<int> &nums) {
    sort(nums.begin(), nums.end());
}

// better
// 
void sortColors1(vector<int> &nums) {
    int count[3] = {0};
    for (int i : nums)
        count[i]++;
    int index = 0;
    for (int i = 0; i < 3; i++) {
        while (count[i]--)
            nums[index++] = i;
    }
}

// optimal
// Dutch National Flag Problem
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 0, 1, 2, 2, 0};
    sortColors(nums);
    for (int i : nums)
        cout << i << " ";
    return 0;
}