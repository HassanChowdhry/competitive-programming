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

void dfs(int node, vi& path, vi& vis, vi& reach, vi& goo, vector<vi>& adj) {
  if (vis[node]) return;
  for (int child: adj[node]) {
    dfs(child, path, vis, reach, goo, adj);
    if (path[child] + 1 > path[node] && reach[child]) {
      reach[node] = 1;
      goo[node] = child;
      path[node] = max(path[node], path[child] + 1);
    }
  }
  vis[node] = 1;
}

void dfs2(int node, vi& goo) {
  cout << node << " ";
  if (node == goo[node]) return;
  dfs2(goo[node], goo);
}

void solve() {
  int n, m; cin >> n >> m;
  vector<vi> adj(n+1);
  int u, v;
  rep(i, m) { cin >> u >> v; adj[u].pb(v); }
  vi vis(n+1, 0), path(n+1, 1), goo(n + 1), reach(n + 1, 0);
  reach[n] = 1;
  for (int i = 1; i <= n; ++i) goo[i]=i;


  dfs(1, path, vis, reach, goo, adj);
  int res = path[1];
  
  if (!reach[1]) { cout << "IMPOSSIBLE"; return; }
  cout << res << ln;
  // for (int i = 1; i <= n; ++i) cout << goo[i] << " ";
  // cout << ln;
  // for (int i = 1; i <= n; ++i) cout << reach[i] << " ";
  // cout << ln;
  dfs2(1, goo);
}

int main() {
  flash;
  solve();
  return 0;
}