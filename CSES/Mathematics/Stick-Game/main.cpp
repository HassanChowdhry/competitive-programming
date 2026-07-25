#include <bits/stdc++.h>
using namespace std;

int n, k;
const int maxK = 101, maxN = 1e6 + 1;
int p[maxN];
int dp[maxN];

// if from i, I can go to a losing state: i wins else i looses
void solve() {
	cin >> n >> k;
  dp[0] = 0;

  for (int i = 1; i <= k; ++i) cin >> p[i];

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (p[j] > i || dp[i]) continue;
      
      dp[i] |= !dp[i - p[j]];
    }

    if (dp[i]) cout << "W";
    else cout << "L";
  }
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	// int t; cin >> t;
  // while (t--) solve();
  solve();
	return 0;
}