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

	sort(coins.begin(), coins.end());

  vector<vector<int>> dp(n+1, vector<int>(target+1));
  for (int i = 0; i < n; ++i)
    { dp[i][0] = 1; }

	for (int i = n-1; i >= 0; --i) {
    for (int j = coins[i]; j < (target+1); ++j)
      { dp[i][j] = (dp[i+1][j] + dp[i][j-coins[i]]) % MOD; }
	}

  cout << dp[0][target];
}