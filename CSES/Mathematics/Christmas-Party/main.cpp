#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int oo = 1e9 + 7;
const ll maxN = 1e6;
ll dp[maxN + 1];
ll n, a, b, ans;


// derangments: (n - 1) * (f(n - 1) + f(n - 2))
// think of this as graph connection: 1 -> 2, now 2 -> 1 
// and we choose (n - 2) other derangents or 2 can continue 
// with (n - 1) connections
void solve() {
	cin >> n;

	dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 2;

	for (int i = 4; i <= n; ++i) {
		dp[i] = (1LL * i - 1LL) * (dp[i - 1] + dp[i - 2]) % oo;
	}

	cout << dp[n];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
	return 0;
}