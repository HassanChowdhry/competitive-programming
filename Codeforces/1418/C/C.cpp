#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  
  sort(c.begin(), c.end());
  vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0)); 
  
  dp[0][0] = true;

  for (int i = 1; i <= n; ++i) {
    for (int j = k; j >= 0; --j) {
      if (j - c[i] < 0) continue;
      for (int z = j; z >= 0; --z) {
        if (dp[j - c[i]][z] > 0) {
          dp[j][z] = true;
        }

        if (z >= c[i] && dp[j - c[i]][z - c[i]]) {
          dp[j][z] = true;
        }
      } 
    }
  }

  vector<int> ans;
  for (int i = 0; i <= k; ++i) {
    if (dp[k][i])
    ans.push_back(i);
  }

  cout << ans.size() << "\n";
  for (int i: ans) cout << i << " ";
}

int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);

  solve();

  return 0;
}