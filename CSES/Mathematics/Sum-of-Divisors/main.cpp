#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll oo = 1e9 + 7;
const ll inv2 = (oo + 1LL) / 2LL;
ll n, i, q, j, ans, g, d;

ll gauss(ll a, ll b) {
	// n ( n + 1 ) / 2 (instead of div by 2, we multiply by INV MOD of 2)
	// (b - a) * a + ((b - a) * (b - a - 1)) / 2
	d = (b - a) % oo;
	a = a % oo;
	ll p1 = (d * a) % oo;
	ll p2 = (d * (d - 1LL) % oo) * inv2 % oo;

	return (p1 + p2) % oo;
}

void solve() {
	cin >> n;
	i = 1LL;
	while (i <= n) {
		// ans = i..n sum (i * (n / i));

		// q = (n / i)

		q = (n / i);

		
		// j = (n / q) + 1
		j = (n / q) + 1;
		g = gauss(i, j);
		ans = (ans + (g * q % oo) % oo) % oo;
		
		// cout << i << " " << j << " " << q << " " << g << "\n";
		
		i = j;
	}

	cout << ans << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	solve();
	return 0;
}