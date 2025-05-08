#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  int n; cin >> n;
  vector<ll> nums(n, 0); input(nums, n);
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  ll total = 0;
  rep(i, n) 
    { total += nums[i]; dp[i][i] = nums[i]; }

  for (ll i = n - 2; i >= 0; --i) {
    for (ll j = 1; j < n; ++j) {
      if (i == j) continue;
      dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
    }
  }

  cout << (total + dp[0][n-1]) / 2;

}

int main() {
  flash;
  solve();
  return 0;
}