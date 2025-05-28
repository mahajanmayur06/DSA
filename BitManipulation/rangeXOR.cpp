#include <bits/stdc++.h>
using namespace std;

// Find xor of all numbers from 1 to n
int findXOR (int n) {
    if (n % 4 == 0) {
        return n;
    }
    else if (n % 4 == 1) {
        return 1;
    }
    else if (n % 4 == 2) {
        return n + 1;
    }
    return 0;
}

int findrangeXOR (int l, int r) {
    return findXOR(r) ^ findXOR(l - 1);
}

int main() {
    
    return 0;
}