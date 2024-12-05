#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i,n) for(int i=0; i<n ; ++i)
#define repx(i,n,x) for(int i=x; i<n ; ++i)
#define per(i,n) for(int i=n-1; i>=0; --i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
#define ln "\n"
int MOD=1000000007;

void solve() {
  int n; cin >> n;
  vector<int> nums(n); input(nums, n);
  int sum = accumulate(nums.begin(), nums.end(), 0) + 1;
  vector<vector<int>> dp(n, vector<int>(sum, 0));

  dp[0][nums[0]] = 1;
  rep(i, n) dp[i][0] = 1;
  int total = 1;

  repx(i, n, 1) {
    repx(j, sum, 1) {
      dp[i][j] = dp[i-1][j];
      if (dp[i][j]) continue;

      if (nums[i] <= j)
        { dp[i][j] = dp[i-1][j - nums[i]]; if (dp[i][j]) ++total; }
    }
  }
  
  cout << total << ln;
  repx(i, sum, 1) {
    if (!dp[n-1][i]) continue;
    cout << i << " ";
  }
}

int main() {
  flash
  solve();
  return 0;
}