#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

long long dp[300005];

void solve() {
  int n; cin >> n;
  vector<long long> nums(n + 1);

  for (int i = 0; i < 300005; ++i) {
    dp[i] = 1e9;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
    dp[nums[i]] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = i + i; j <= n; j += i) {
      dp[j] = min(dp[j], dp[j/i] + dp[i]);
      // cout << dp[j] << " " << j << " " << i << " " << dp[i] << ln;
    }
  }

  for (int i = 1; i <= n; ++i) {
    // cout << dp[i] << " " << i << " ";
    if (dp[i] == 1e9) cout << "-1" << " ";
    else cout << dp[i] << " ";
  } cout << ln;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}