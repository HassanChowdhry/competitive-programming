#include <bits/stdc++.h>
using namespace std;

int INF = 1e9 + 7;
void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(2, INF));
  
  for (int i = 1; i <= n; ++i) cin >> a[i];

  if (n == 1) {
    cout << a[1] << "\n";
    return;
  }

  dp[1][0] = a[1];
  dp[2][0] = a[1] + a[2];

  for (int i = 2; i <= n; ++i) {
    dp[i][0] = min({
      dp[i][0],
      dp[i-1][1] + a[i],
      dp[i-2][1] + a[i] + a[i-1]
    });

    dp[i][1] = min(
      { dp[i][1], dp[i-1][0], dp[i-2][0] }
    );
    // cout << a[i] << " " << dp[i][0] << " " << dp[i][1] << "\n";
  }


  int res = min(dp[n][0], dp[n][1]);
  cout << res << "\n";
}

int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while (t--)
  solve();

  return 0;
}