#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int oo = 1e9 + 7;
const ll maxN = 1e6;
ll fact[maxN + 1], invfact[maxN + 1], cnt[27];
ll n, a, b, ans;

// fact(n) / (fact[k] * fact[n - k])

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
	for (int i = 1; i <= maxN; ++i) {
		fact[i] = (fact[i - 1] * i) % oo;
	}

	invfact[0] = 1;

	for (int i = 1; i <= maxN; ++i) {
		invfact[i] = fastpow(fact[i], oo-2) % oo;
	}
}


void solve() {
	string s; cin >> s;
	n = s.size();
	_fact(); 
	
	for (char c: s) {
		++cnt[c - 'a'];
	}
	
  	ans = fact[n];

	for (int i = 0; i < 26; ++i) {
		ans = (ans * invfact[cnt[i]]) % oo;	
	}

	cout << ans;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  	solve();
	return 0;
}