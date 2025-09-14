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

void dfs(int u, vector<vi>& adj, vi& vis) {
  if (vis[u]) return;
  vis[u]=1;
  for (int v: adj[u]) if (!vis[v]) dfs(v, adj, vis);
}

void dfs2(int u, vl& parent, vi& vis, vi& res) {
  res.pb(u);
  if (parent[u] == u) return;
  vis[u] = 1;
  if (!vis[parent[u]]) dfs2(parent[u], parent, vis, res);
}
 
void solve() {
  int n, k; cin >> n >> k;
  int u, v, c;
  vector<tuple<int, int, int>> edges(k);
  vector<vi> adj(n + 1), radj(n + 1);
  vi vis1(n+1), vis2(n+1), vis3(n + 1), res;
  vl dist(n + 1, 0), parent(n + 1, 0);
  for (int i = 1; i <= n; ++i) parent[i] = i;

  rep(i, k) {
    cin >> u >> v >> c;
    edges[i] = { u, v, c };

    adj[u].pb(v);
    radj[v].pb(u);
  }

  dfs(1, adj, vis1);
  dfs(n, radj, vis2);
  bool up = true; 
  for (int i = 0; i < n && up; ++i) {
    up = false;
    for (auto &[u, v, c]: edges) {
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        parent[v] = u;
        up = true;
        
        // cout << i << " " <<  << u << " " << v << " " << ln;
        if (i == n-1) { 
          // cout << v << " p:  " << parent[v] << " // "<< u << " p: " << parent[u] << ln;
          cout << "YES" << ln; 
          ll x = parent[v];
          for (int i = 0; i < n; ++i) x = parent[x];
          for (ll z = x;; z=parent[z]) {
            res.pb(z);
            if (z == x && res.size() > 1) break;
          }
          reverse(res.begin(), res.end());
          for (int node: res) cout << node << " ";
          return; 
        }
      }
    }
  }

  cout << "NO" << ln;
}

int main() {
  flash;
  solve();
  return 0;
}