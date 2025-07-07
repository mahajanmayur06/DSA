#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0)
        return 0;
    int win = 1;
    unordered_map<char, int> map;
    int l = 0, r = 1;
    map[s[0]] = 0;
    while (r != n) {
        if (map.count(s[r])) {
            if (map[s[r]] >= l)
                l = map[s[r]] + 1;
        }
        map[s[r]] = r;
        win = max(win, r - l + 1);
        r++;
    }
    return win;
}
int main() {
    
    return 0;
}