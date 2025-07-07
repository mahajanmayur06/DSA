#include <bits/stdc++.h>
using namespace std;

int searchKMP (string& text, string& pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    lps[0] = 0;
    int prevLPS = 0, i = 1, j = 0;
    while (i < n) {
        if (pattern[i] == pattern[prevLPS]) {
            lps[i] = prevLPS + 1;
            prevLPS++;
            i++;
        }
        else if (prevLPS == 0) {
            lps[i] = 0;
            i++;
        }
        else {
            prevLPS = lps[prevLPS - 1];
        }
    }
    i = 0, j = 0;

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }
        if (j == n) {
            return i - n;
        }
    }
    return -1;
}

int main() {
    
    return 0;
}