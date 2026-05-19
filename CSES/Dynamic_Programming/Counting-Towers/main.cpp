#include <bits/stdc++.h>
using namespace std;

#define ll long long
int oo=1e9+7;

void solve() {

  int t; cin >> t;
  int n = 1e6+5;
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  dp[1][0] = 1;
  dp[1][1] = 1;

  for (int i = 2; i <= n; ++i) {
    dp[i][0] = 2LL * dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = 4LL * dp[i - 1][1] + dp[i - 1][0];
    dp[i][0] = (dp[i][0] % oo + oo) % oo;
    dp[i][1] = (dp[i][1] % oo + oo) % oo;
  }

  while (t--) {
    int m; cin >> m;
    ll res = (dp[m][1] + dp[m][0]) % oo;
    cout << res << "\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}