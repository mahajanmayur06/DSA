#include <bits/stdc++.h>
using namespace std;

int solve (vector<int>& nums, int i, int j) {
    if (i > j) return 0;

    int maxCoins = 0;

    for (int k = i; k <= j; k++) {
        int coins = nums[i - 1] * nums[k] * nums[j + 1]
                    + solve (nums, i, k - 1)
                    + solve (nums, k + 1, j);

        maxCoins = max(maxCoins, coins);
    }

    return maxCoins;
}

int maxCoins(vector<int>& balloons) {
    int n = balloons.size();
    vector<int> nums(n + 2);
    nums[0] = nums[n + 1] = 1;

    for (int i = 0; i < n; i++) {
        nums[i + 1] = balloons[i];
    }

    return solve (nums, 1, n);
}

int main() {
    vector<int> balloons = {3, 1, 5, 8};
    cout << "Max coins: " << maxCoins(balloons) << endl;
    return 0;
}
