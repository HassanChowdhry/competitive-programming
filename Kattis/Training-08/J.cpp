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
ll INF = 1e9;
void solve() {
  int n, k, len; cin >> n >> k; len = (k + 1)/2;
  vector<vl> cnt('z'+ 5, vl('z'+ 5, INF));
  vector<vl> dp(len + 2, vl('z' + 5, INF));

  for (int i = 0; i < n; ++i) {
    char a, b; int x; cin >> a >> b >> x;
    dp[1][a] = 0;
    cnt[a][b] = x;
  }

  if (k == 2) {
    ll res = INF;
    for (int a = 'a'; a <= 'z'; ++a) {
      res = min(res, cnt[a][a]);
    }
    if (res == INF) cout << -1;
    else cout << res;
    return;
  }

  for (int l = 2; l <= len; ++l) {
    for (int a = 'a'; a <= 'z'; ++a) {
      for (int b = 'a'; b <= 'z'; ++b) {
          if (k % 2 == 0 && l == len ) {
            dp[l][b] = min(dp[l][b], dp[l-1][a] + cnt[a][b] + cnt[b][a] + cnt[b][b]);
          } else { 
            dp[l][b] = min(dp[l][b], dp[l-1][a] + cnt[a][b] + cnt[b][a]);
          }
      }
    }
  }

  ll res = INF;
  for (int i = 'a'; i <= 'z'; ++i) {
    res = min(res, dp[len][i]);
  }

  if (res == INF) cout << -1;
  else cout << res;
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}