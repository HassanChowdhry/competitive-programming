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
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  ll n, w; cin >> n >> w;

  vector<pair<ll, ll>> nums(n, {0, 0}); // weight, val
  ll v = 0;
  for (int i = 0; i < n; ++i) {
    ll x, y; cin >> x >> y; v += y;
    nums[i].fs = x; nums[i].sc = y;
  }

  vector<vl> dp(n + 1, vl(v + 1, 1e9+7));
  ll res = 0;
  // cout << v;
  for (int i = 0; i <= n; ++i) dp[i][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (ll j = 1; j <= v; ++j) {
      if (j - nums[i-1].sc >= 0 && dp[i-1][j-nums[i-1].sc] + nums[i-1].fs <= w) {
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-nums[i-1].sc] + nums[i-1].fs);
        res = max(res, j);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= v; ++j) {
  //     cout << dp[i][j] << " ";
  //   } cout << ln;
  // }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}