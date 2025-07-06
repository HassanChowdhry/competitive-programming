#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;

void solve() {
  ll n; cin >> n;
  ll total = n * (n + 1) / 2;
  if (total % 2) { cout << 0; return; }
  total /= 2;
  vector<vector<ll>> dp(n+1, vector<ll>(total+1, 0));
  rep(i, n + 1) dp[i][0] = 1;

  repx(i, 1, n + 1) {
    repx(j, 1, total + 1) {
      if (j - i < 0) dp[i][j] = dp[i-1][j];
      else dp[i][j] = (dp[i-1][j] + dp[i-1][j - i]) % MOD;
    }
  }

  cout << dp[n-1][total]; // get the solution for the set that does contain `n`
  // ll inverse = (MOD + 1) / 2;
  // cout << dp[n][total] * inverse % MOD;
}

int main() {
  flash;
  solve();
  return 0;
}