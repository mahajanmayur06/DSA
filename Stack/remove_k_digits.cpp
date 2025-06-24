#include <bits/stdc++.h>
using namespace std;

string removeKdigits1(string num, int k) {
    int n = num.size(), count = k;
    string res = "";

    for (int i = 0; i < n; i++) {
        while (!res.empty() && res.back() > num[i] && count > 0) {
            res.pop_back();
            count--;
        }
        res.push_back(num[i]);
        if (res.size() == 1 && res.back() == '0') {
            res.pop_back();
        }
    }

    while (count > 0 && !res.empty()) {
        res.pop_back();
        count--;
    }
    if (res.empty()) return "0";
    return res;
}

string removeKdigits(string num, int k) {
    int n = num.size(), count = k;
    string res = "";
    stack<char> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() > num[i] && count > 0) {
            s.pop();
            count--;
        }
        s.push(num[i]);
    }

    while (!s.empty()) {
        if (count > 0){
            count--;
        }
        else {
            res.push_back(s.top());
        }
        s.pop();
    }

    reverse(res.begin(), res.end());

    int i = 0;
    while (i < res.size() && res[i] == '0') i++;

    res = res.substr(i);

    if (res.empty()) return "0";
    return res;
}


int main() {
    cout << removeKdigits("1432219", 3) << endl;
    cout << removeKdigits("10200", 1) << endl;
    cout << removeKdigits("10", 2) << endl;
    cout << removeKdigits("33526221184202197273", 19) << endl;
    cout << removeKdigits("1022", 2) << endl;
    return 0;
}