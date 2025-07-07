#include <bits/stdc++.h>
using namespace std;

string minimum_window_substring (string s, string t) {
    int n = s.size();
    int size = t.size();
    unordered_map<char, int> freq;
    int count = 0;
    for (int i = 0; i < size; i++) {
        freq[t[i]]++;
    }
    int l = 0, r = 0, start = -1, minLength = INT_MAX;
    while (r < n) {
        if (freq[s[r]] > 0) {
            count++;
        }
        freq[s[r]]--;
        while (count == size) {
            if (r - l + 1 < minLength) {
                minLength = min(minLength, r - l + 1);
                start = l;
            }
            freq[s[l]]++;
            if (freq[s[l]] > 0) {
                count--;
            }
            l++;
        }
        r++;
    }
    if (start == -1) {
        return "";
    }
    return s.substr(start, minLength);
}

int main() {
    
    return 0;
}