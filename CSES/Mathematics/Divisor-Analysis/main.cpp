#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll oo = 1e9 + 7;
const ll inv2 = (oo + 1LL) / 2LL;
const int maxN = 1e5+1;
ll n, d, k;
ll D[maxN], K[maxN];

ll fastpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % oo;
		}

		a = (a * a) % oo;
		b >>= 1;
	}

	return res;
}

void solve() {
	cin >> n;
	// CP handbook for re-explain
	for (int i = 1; i <= n; ++i) {
		cin >> d >> k;
		D[i] = d; K[i] = k;
	}

	// tau: number of divs, tau = π(ki + 1)
	ll tau = 1;
	for (int i = 1; i <= n; ++i) {
		tau = (tau * (K[i] + 1)) % oo;
	}

	// sigma: sum of divisors, sigma = π((ak+1 - 1) / (a - 1)) or 
	// π((ak+1 - 1) * INV(a - 1))
	ll sigma = 1;
	for (int i = 1; i <= n; ++i) {
		ll top = (fastpow(D[i], K[i] + 1) - 1) % oo;
		ll down = fastpow(D[i]-1, oo-2); // see fermats little theorem for why this is INV

		sigma = (sigma * ((top * down) % oo)) % oo;
	}

	// mu: product of divisors, mu = π(n^(tau(n) / 2)) or π(n^(tau(n) * inv2))
	ll mu = 1;
	ll tau_i = 1;
	for (int i = 1; i <= n; ++i) {
		ll mu_i = fastpow(D[i], K[i] * ( K[i] + 1LL ) / 2LL);
		mu = fastpow(mu, K[i] + 1) * fastpow(mu_i, tau_i) % oo;
		tau_i = (tau_i * (K[i] + 1)) % (oo-1); // cant really just store as tau % oo, tau_i is used as an exponent therefore FLT -> a^(b) = a^(b mod (oo - 1)) % oo
	}

	cout << tau << " " << sigma << " " << mu;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	solve();
	return 0;
}