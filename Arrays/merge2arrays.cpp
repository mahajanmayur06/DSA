#include <bits/stdc++.h>
using namespace std;
// merge two sorted arrays

// time O(n + m) space O(n + m)
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> merged(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n) {
        merged[k++] = arr1[i++];
    }
    while (j < m) {
        merged[k++] = arr2[j++];
    }
    for (int i = 0; i < n; i++) {
        arr1[i] = merged[i];
    }
    for (int i = 0; i < m; i++) {
        arr2[i] = merged[n + i];
    }
}

// one of the optimal
// time O(min(n, m) + O(nlogn) + O(mlogm)) space O(1)
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i = n - 1, j = 0;
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
        else {
            break;
        }
        i--;
        j++;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

// Optimal approach
// gap method, intution from sorting technique, shell sort
// Large gaps help move larger elements towards the end and smaller ones towards the beginning quickly.
// By the time the gap becomes 1 (simple adjacent comparison), most elements are close to their correct positions.

// Because of the previous passes with larger gaps!

// In bubble sort, you’re only fixing local errors each time, so you need many passes to push elements far.

// But in the gap method, earlier passes already moved large elements forward and small ones backward quickly using large gaps.

// By the time we reach gap = 1, the array is almost sorted — so only minor local adjustments (small swaps) are needed, and just one pass is enough.

// time O(log2(n + m)) * O(n + m) space O(1)
void swapIfGreater (vector<int>& a, vector<int>& b, int i1, int i2) {
    if (a[i1] > b[i2]) {
        swap(a[i1], b[i2]);
    }
}

void merge(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int len = n + m;
    int gap = (len + 1) / 2; // ceil(len / 2)

    while (gap > 0) {
        int l = 0;
        int r = gap; // left + gap
        while(r < len) {
            // arr1[i] and arr2[j]
            if (l < n && r >= n) {
                swapIfGreater(arr1, arr2, l, r - n);
            }
            // arr2[i] and arr2[j]
            else if (l >= n) {
                swapIfGreater(arr2, arr2, l - n, r - n);
            }
            // arr1[i] and arr1[j]
            else {
                swapIfGreater(arr1, arr1, l, r);
            }
            l++;
            r++;
        }
        gap = gap == 1 ? 0 : (gap + 1) / 2; // ceil(gap / 2)
    }
}

int main() {
    
    return 0;
}