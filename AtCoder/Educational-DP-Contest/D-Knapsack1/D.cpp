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
  for (int i = 0; i < n; ++i) cin >> nums[i].fs >> nums[i].sc;

  vector<vl> dp(n + 1, vl(w + 1, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (j - nums[i - 1].fs >= 0) {
        dp[i][j] = max(dp[i-1][j], dp[i-1][j - nums[i-1].fs] + nums[i-1].sc);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[n][w];
}

int main() {
  flash;
  solve();
  return 0;
}