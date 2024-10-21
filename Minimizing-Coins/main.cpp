#include <iostream>
#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;

int main() {
	int n, target;

	cin >> n >> target;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) 
		{ cin >> coins[i]; }

	vector<int> dp(target + 1, inf);

	dp[0] = 0;
	for (int i = 0; i < target; ++i) {
		if (dp[i] == inf) continue;

		for (int coin: coins) {
			if ((i+coin) <= target)
				{ dp[i+coin] = min(dp[i+coin], 1 + dp[i]); }
		}
	}
	cout << (dp[target] != inf ? dp[target] : -1);
}