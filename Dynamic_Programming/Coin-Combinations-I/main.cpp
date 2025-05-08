#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
	int n, target;

	cin >> n >> target;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) 
		{ cin >> coins[i]; }

	vector<int> dp(target + 1, 0);

	dp[0] = 1;
	for (int i = 0; i < target; ++i) {
		if (!dp[i]) continue;

		for (int coin: coins) {
			if ((i+coin) <= target)
				{ dp[i+coin] = (dp[i+coin] + dp[i]) % MOD; }
		}
	}
	cout << dp[target];
}