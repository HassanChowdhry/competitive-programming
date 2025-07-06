#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int n, price; cin >> n >> price;
  vector<int> prices(n), pages(n);
  vector<vector<int>> dp(n+1, vector<int>(price+1, 0));
  
  for (int i = 0; i < n; ++i) 
    { cin >> prices[i]; }

  for (int i = 0; i < n; ++i) 
    { cin >> pages[i]; }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= price; ++j) {
      if ((j - prices[i-1]) < 0 ) 
        { dp[i][j] = dp[i-1][j]; continue; }
      
      dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j-prices[i-1]]);
    }
  }

  cout << dp[n][price];
}