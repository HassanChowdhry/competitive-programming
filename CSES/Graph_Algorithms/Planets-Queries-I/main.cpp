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
  ll n, q; cin >> n >> q;
  int LOG = 31;
  vi adj(n + 1), depth(n + 1); for(int i = 1; i <= n; ++i) cin >> adj[i];
  vector<vi> dp(n + 1, vi(LOG));

  for (int i =1; i <=n; ++i) dp[i][0] = adj[i];
  for (int p = 1; p < LOG; ++p) {
    for (int i = 1; i <= n; ++i) dp[i][p] = dp[ dp[i][p-1] ][p-1];
  }

  int x, k;
  for (int i = 0; i < q; ++i) {
    cin >> x >> k;

    for (int p = 0; p < LOG; ++p) if (k & ( 1 << p)) x = dp[x][p];
    cout << x << ln;
  }

}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}