#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << (13 >> 1) << endl; // right shift 13 by 1 bit -> 6
    cout << (13 << 1) << endl; // left shift 13 by 1 bit -> 26
    cout << !13 << endl;  // logical NOT of 13 -> 0
    cout << ~13 << endl; // bitwise NOT of 13 -> -14
    cout << ~6 << endl; // bitwise NOT of 6 -> -7
    cout << ~(-13) << endl;  // bitwise NOT of -13 -> 12
    cout << ~INT_MAX << endl;  // bitwise NOT of INT_MAX -> -2147483648 
    return 0;
}