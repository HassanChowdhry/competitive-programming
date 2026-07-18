#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll oo = 1e9 + 7;
ll n, k, res, prod, divs;
ll primes[21], ans[21];


// we use the inc/exc principle
// prime multiples = sum(n / pi)
// but lcm(pi, pi+1) needs to be excluded or we overcount
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> primes[i];
	}
	
	for (int mask = 1; mask < ( 1 << k ); ++mask) {
		divs = __builtin_popcount(mask);
		// int ok = 1;
		// 01, 10, 11
		// cout << mask << ": ";
		prod = n;
		for (int i = 1; i <= k; ++i) {
			// cout << (1 << (i-1)) << " ";
			if (mask & ( 1 << (i-1))) { // if we consider ith prime
				prod = (prod / primes[i]);
			}
		}

		ans[divs] += prod;
	}
	res = 0;
	
	for (int i = 0; i <= k; ++i) {
		if (i & 1) {
			res += ans[i];
		} else {
			res -= ans[i];
		}
	}

	cout << res;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	solve();
	return 0;
}