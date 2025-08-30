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
int vis[200005];

pair<ll, ll> dfs(ll node, ll parent, vector<vl>& edges) {
  if (vis[node]) return {1, 1};
  vis[node]=1;
  ll w = 1, b = 1;
  for (ll child : edges[node]) {
    if (vis[child] || node == parent) continue;
    auto [white, black] = dfs(child, node, edges);
    w *= (white + black) % MOD;
    b *= white % MOD;
    b %= MOD;
    w %= MOD;
  }

  return { w, b };
}


void solve() {
  int n; cin >> n;
  vector<vl> edges(n + 1);
  int u, v;
  vector<pair<ll, ll>> dp(n + 1, {1, 1});
  rep(i, n-1) {
    cin >> u >> v; 
    edges[u].pb(v);
    edges[v].pb(u);
  }

  // white -> dp[i][0] = π dp[c][0] + dp[c][1]
  // black -> dp[i][0] = π dp[c][0]

  auto res = dfs(1, 0, edges); // node, parent,...
  ll out = (res.fs + res.sc) % MOD;
  cout << out;

}

int main() {
  flash;
  solve();
  return 0;
}