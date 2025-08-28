#include <bits/stdc++.h>
using namespace std;

int solve(string& str, int i, int j, bool isTrue) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }

    int ways = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        char op = str[k];

        // Recursively evaluate left and right parts
        int lT = solve(str, i, k - 1, true);
        int lF = solve(str, i, k - 1, false);
        int rT = solve(str, k + 1, j, true);
        int rF = solve(str, k + 1, j, false);

        if (op == '&') {
            if (isTrue) {
                ways += lT * rT;
            } else {
                ways += lT * rF + lF * rT + lF * rF;
            }
        } else if (op == '|') {
            if (isTrue) {
                ways += lT * rT + lT * rF + lF * rT;
            } else {
                ways += lF * rF;
            }
        } else if (op == '^') {
            if (isTrue) {
                ways += lT * rF + lF * rT;
            } else {
                ways += lT * rT + lF * rF;
            }
        }
    }

    return ways;
}

int main() {
    string str = "T|F&T^F"; // Example input
    int n = str.length();
    cout << "Ways to evaluate to True: " << solve(str, 0, n - 1, true) << endl;
    return 0;
}
