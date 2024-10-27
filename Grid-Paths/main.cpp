#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
  int n; cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  vector<vector<int>> dp(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '.')
        { dp[i][j] = -1; }
      else
        { dp[i][j] = 0; }
    }
  }

  bool canGoDown = true, canGoRight = true;
  for (int i = 0; i < n; ++i) { 
      if (dp[i][0] != 0 && canGoDown)
        { dp[i][0] = 1; }
      else
        { canGoDown = false; }

      if (dp[0][i] != 0 && canGoRight)
        { dp[0][i] = 1; }
      else
        { canGoRight = false; }
  }
  

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (!dp[i][j])
        { continue; }

      dp[i][j] = (max(dp[i-1][j], 0) + max(0, dp[i][j-1])) % MOD;
    }
  }
  
  cout << (dp[n-1][n-1]);
}