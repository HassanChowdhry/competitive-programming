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

int dfs(int node, vector<vi>& adj, vi& dp, vector<bool>& vis) {
  if (vis[node]) return dp[node] + 1;
  int res = 0;
  for (int child: adj[node]) {
    if (vis[child]) { res = max(res, dp[child] + 1); continue; }
    res = max(res, dfs(child, adj, dp, vis) + 1);
  }
  
  // cout << res << ln;
  vis[node] = true;
  dp[node] = res;
  return dp[node];
}
void solve() {
  int n, e; cin >> n >> e;
  vector<vi> adj(n + 1);
  for (int i = 0; i < e; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }

  vector<int> dp(n + 1, 0);
  vector<bool> visit(n + 1, false);
  
  // run a dfs through every n and dp[parent] += dp[child]

  for (int i = 1; i <= n; ++i) dfs(i, adj, dp, visit);
  int res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, dp[i]);
  
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}