#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define printv(x) cout << #x << " is " << x << endl;
#define printarr(c) { cout << #c << " = [ "; for (auto& element : c) { cout << element << " ";} cout << "]" << endl;}
#define vi vector<int>
#define f(i,a,b) for ( int i = a; i < b; i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define print(a) cout<<a<<endl

const int MOD = 1e9 + 7, N = 1e5;

int gcd (int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

vector<int> sieve (int n) {
	vector<int> isPrime (n + 1, 1);
	isPrime[0] = isPrime[1] = false;
	
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return isPrime;
}

long long fastExpoMod(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}

vector<int> prefixSum (vector<int>& nums) {
	vector<int> arr = nums;
	partial_sum(arr.begin(), arr.end(), arr.begin());
	return arr;
}

vector<long long> fact(N), inv(N);

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) 
		fact[i] = fact[i-1]*i % MOD;

    inv[N-1] = fastExpoMod(fact[N-1], MOD-2, MOD);
	
    for (int i = N-2; i >= 0; i--) 
		inv[i] = inv[i+1]*(i+1) % MOD;
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
}

void solve(){

	int n;cin>>n;
	vi arr(n);f(i,0,n)cin>>arr[i];


}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	// int t;cin>>t;
	// while(t--)
	// {
	// 	solve();
	// }
	cout << gcd(25, 10) << endl;
	return 0;

}