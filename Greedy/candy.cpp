#include <bits/stdc++.h>
using namespace std;

// Greedy Space (2N)
int candy1(vector<int>& ratings) {
    int n = ratings.size();
    int count = 0;
    vector<int> left(n, 1), right(n, 1);

    for (int i = 1; i < n; i++) {

        if (ratings[i] > ratings[i - 1]) {
            left[i] = 1 + left[i-1];
        }
        if (ratings[n - i - 1] > ratings[n - i]) {
            right[n - i - 1] = 1 + right[n - i];
        }
    }

    for (int i = 0; i < n; i++) {
        count += max(left[i], right[i]);
    }
    return count;
}

// Optimal space (N)
int candy2(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n, 1);

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = 1 + left[i-1];
        }
    }
    int count = left[n - 1], right = 1;
    
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right++;
        }
        else {
            right = 1;
        }
        count += max(left[i], right);
    }

    return count;
}

// Slope method
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int count = 1, i = 1;
    
    while (i < n) {
        if (ratings[i] == ratings[i-1]) {
            count++;
            i++;
            continue;
        }

        int peak = 1, down = 1;
        while (i < n && ratings[i] > ratings[i - 1]) {
            peak++;
            count += peak;
            i++;
        }
        while (i < n && ratings[i] < ratings[i - 1]) {
            count += down;
            down++;
            i++;
        }

        count += max(0, down - peak);
    }

    return count;
}

int main() {
    
    return 0;
}