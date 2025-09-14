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

void dfs(int u, vector<vector<int>>& edges, vector<int>& vis) {
  if (vis[u]) return;
  vis[u]=1;
  for (int v: edges[u]) if (!vis[v]) dfs(v, edges, vis);
}
void solve() {
  int n, k; cin >> n >> k;
  vector<ll> dist(n+1, LLONG_MIN);
  vector<vector<int>> edges(k, vector<int>(3)); // start, end, cost
  vector<vector<int>> adj(n + 1), radj(n + 1);
  vector<int> vis1(n + 1),vis2(n + 1);
  int u, v, c;
  rep(i, k) {
    cin >> u >> v >> c;
    edges[i][0] = u;
    edges[i][1] = v;
    edges[i][2] = c;

    adj[u].pb(v);
    radj[v].pb(u);
  }
  dfs(1, adj, vis1);
  dfs(n, radj, vis2);
  // way to check a cycle in BL we run till n-1 iteration, 
  // on nth iteration we run again and see if we have improvement and we can reach both v from 1 and n. 
  dist[1] = 0;
  bool improve = true;
  for (int i = 0; i < n && improve; ++i) {
    improve = false;
    for (vector<int> edge: edges) {
      u = edge[0], v = edge[1], c = edge[2];
      if (dist[u] == LLONG_MIN) continue;
      if (dist[u] + c > dist[v]) {
        improve = true;
        dist[v] = dist[u] + c;
        if (i == n-1 && vis1[v] && vis2[v]) { cout << -1; return; }
      }
    }
  }
  if (dist[n] == LLONG_MIN) { cout << -1; return; }
  cout << dist[n];

}

int main() {
  flash;
  solve();
  return 0;
}