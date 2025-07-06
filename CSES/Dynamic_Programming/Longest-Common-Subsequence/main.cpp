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
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n, m; cin >> n >> m;
  vector<int> l(n, 0), r(m, 0);
  input(l, n); input(r, m);
  vector<vector<int>> dp(n+1, vector(m+1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (l[i-1] == r[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  
  int k = dp[n][m];
  cout << k << ln;
  vector<int> res(k, 0); int idx = k-1;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (dp[i][j] == 0) break;
  
    if (l[i-1] == r[j-1]) { res[idx--] = l[i-1]; --i; --j; }
    else if (dp[i][j-1] > dp[i-1][j]) { --j; }
    else { --i; }
  }

    // for (int i = 0; i <= n; ++i) {
    //   for (int j = 0; j <= m; ++j) {
    //     cout << dp[i][j] << " ";
    //   } cout << ln;
    // }

  rep(i, k) cout << res[i] << " ";

  // cout << dp[n][m];
}

int main() {
  flash;
  solve();
  return 0;
}