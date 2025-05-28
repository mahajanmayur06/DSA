#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int divide (int dividend, int divisor) {
    int sum = 0, count = 0;
    while (sum + divisor <= dividend) {
        sum += divisor;
        count++;
    }
    return count;
}

int main()
{
    cout << divide(7, -3);
    return 0;
}