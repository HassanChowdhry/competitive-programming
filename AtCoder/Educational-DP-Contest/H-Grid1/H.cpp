#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>
int MOD=1000000007;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  vector<vl> dp(n, vl(m, 0));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> grid[i][j];
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) cout << grid[i][j] << " "; 
  //   cout << ln;
  // }
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    if (grid[i-1][0] == '#' || dp[i-1][0] == 0) dp[i][0] = 0;
    else dp[i][0] = 1;
  }
  for (int i = 1; i < m; ++i) {
    if (grid[0][i-1] == '#' || dp[0][i-1] == 0) dp[0][i] = 0;
    else dp[0][i] = 1;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (grid[i][j] == '#') continue;
      ll top = (grid[i-1][j] == '#' ? 0 : dp[i-1][j]) % MOD;
      ll left = (grid[i][j-1] == '#' ? 0 : dp[i][j-1]) % MOD;
      ll res = (top + left) % MOD;
      dp[i][j]=res;
    } 
  }

  cout << dp[n-1][m-1];
}

int main() {
  flash;
  solve();
  return 0;
}