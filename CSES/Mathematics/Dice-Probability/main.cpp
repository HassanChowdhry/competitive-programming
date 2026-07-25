#include <bits/stdc++.h>
using namespace std;

int n, a, b;
const int maxN = 101, maxM = 610;
double dp[maxN][maxM];

// if from i, I can go to a losing state: i wins else i looses
void solve() {
	cin >> n >> a >> b;
  // dp[i][j] = the probablity of making j in i rolls
  // each throw is an independent event of 1/6 for each outcome
  // independent events have a cool property of being added
  // successive throws need to be multiplied probablity of making 1 given x = x * 1/6

  for (int i = 1; i <= 6; ++i) dp[1][i] = (1.0/6.0);

  for (int i = 2; i <= n; ++i) {
    for (int j = i; j <= 6 * i; ++j) {
      for (int k = 1; k <= 6; ++k) {
        if (k >= j) continue;
        dp[i][j] += (dp[i-1][j - k] * 1.0/6.0);
      }
    }
  }

  double res = 0;

  for (int i = a; i <= b; ++i) {
    res += dp[n][i];
  }

  cout << fixed << setprecision(6) << res;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	// int t; cin >> t;
  // while (t--) solve();
  solve();
	return 0;
}