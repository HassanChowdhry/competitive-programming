#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int oo = 1e9 + 7;
const ll maxN = 1e6;
ll fact[maxN + 1], invfact[maxN + 1];
ll n, m;

ll fastpow(ll x, ll y) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = (res * x) % oo;
		}

		x = (x * x) % oo;
		y >>= 1;
	}

	return res;
}

void _fact() {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = fact[i - 1] * i % oo;
	}

	for (int i = 0; i <= n; ++i) {
		invfact[i] = fastpow(fact[i], oo-2);
	}
}

// CATALAN numbers
// inv(n + 1) * (2n choose n)
// (2n choose n) = 2n! * inv(n!) * inv(2n-n!)
void solve() {
	cin >> n;
	if (n % 2) {
		cout << 0;
		return;
	}
	m = n / 2LL;

	_fact();
	ll inv_m_1 = fastpow(m + 1, oo-2); // inv of N mod M, if M is prime is N^(M-2);
	ll c_m = inv_m_1 % oo * fact[n] % oo * invfact[m] % oo * invfact[m] % oo;
	cout << c_m;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
	return 0;
}

// to scale maybe think
// C(2n, n) - (2n, n - 1)
// C(2n, n - k) - (2n, n - k - 1)
// we remove N choices.