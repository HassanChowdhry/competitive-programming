#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<pair<long, long>> p(n);

  for (int i = 0; i < n; ++i) {
    long c, poww; cin >> c >> poww;
    p[i] = { poww, c };
  }
  
  sort(p.begin(), p.end());
  vector<long> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = p[i].second;
  }
  long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i-1; j >= 0; --j) {
      if (p[i].first - m > p[j].first) break;
      dp[i] += dp[j];
      dp[j] = 0;
    }
    ans = max(ans, dp[i]);
  }

  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}