#include <bits/stdc++.h>
using namespace std;

// This is sub sequence minimum
// void solve (vector<int>& nums, vector<int>& temp, int i, int* sum) {
//     if (i == nums.size()) {
//         *sum += *min_element(temp.begin(), temp.end());
//         return;
//     }

//     temp.push_back(nums[i]);
//     solve(nums, temp, i + 1, sum);
//     temp.pop_back();
//     solve(nums, temp, i + 1, sum);
// }

vector<int> findPSE(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[s.top()] >= nums[i])
            s.pop();
        if (!s.empty())
            res[i] = s.top();
        s.push(i);
    }
    return res;
}

vector<int> findNSE(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> res(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] > nums[i])
            s.pop();
        if (!s.empty())
            res[i] = s.top();
        s.push(i);
    }
    return res;
}

int findMinSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse = findPSE(nums), nse = findNSE(nums);
    int mod = 1e9 + 7;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        total = (total + (nums[i] * left % mod * right % mod)) % mod;
    }
    return total;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    cout << findMinSum(nums) << endl;
    return 0;
}
