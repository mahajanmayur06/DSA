#include <bits/stdc++.h>
using namespace std;

// GCD function
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void FindNumbers(string& str) {
    stringstream ss(str);
    string token;
    vector<string> fractions;

    while (getline(ss, token, '+')) {
        fractions.push_back(token);
    }

    stringstream ss1(fractions[0]);
    int num1, den1;
    getline(ss1, token, '/');
    num1 = stoi(token);
    getline(ss1, token, '/');
    den1 = stoi(token);

    stringstream ss2(fractions[1]);
    int num2, den2;
    getline(ss2, token, '/');
    num2 = stoi(token);
    getline(ss2, token, '/');
    den2 = stoi(token);

    long long resDen = 1LL * den1 * den2;
    long long resNum = 1LL * num1 * den2 + 1LL * num2 * den1;

    int g = gcd(resNum, resDen);
    resNum /= g;
    resDen /= g;

    cout << resNum << "/" << resDen << endl;
}

int main() {
    string s = "1/2+1/3";
    FindNumbers(s);
    return 0;
}
