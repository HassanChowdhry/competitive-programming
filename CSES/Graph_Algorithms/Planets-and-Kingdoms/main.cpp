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

// topo sort
// reverse the graph
// dfs from least ranked on the reverse graph
// each dfs call is a strongly connected componenent. 
void toposort(int node, vector<vi>& adj, vi& vis, vi& take) {
  if (vis[node]) return;
  vis[node]=1;
  
  for (auto child: adj[node]) {
    if (vis[child]) continue;
    toposort(child, adj, vis, take);
  }
  
  take.pb(node);
}

void dfs(int node, vector<vi>& adj, vi& scc, vi& vis, int cluster) {
  if (vis[node]) return;
  vis[node] = 1;

  for (auto child: adj[node]) {
    if (vis[child]) continue;
    dfs(child, adj, scc, vis, cluster);
  }
  scc[node] = cluster;
} 

void kosaraju() {
  int n, k, u, v; cin >> n >> k;

  vector<vi> adj(n+1), radj(n+1);
  vector<int> topo1, vis1(n+1), vis2(n+1), scc(n+1);
  rep(i, k) {
    cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
  }

  for(int i=1; i <= n; ++i) if (!vis1[i]) toposort(i, adj, vis1, topo1);

  int cluster = 1;
  for (int i=n-1; i >= 0; --i) {
    if (vis2[topo1[i]]) continue;
    dfs(topo1[i], radj, scc, vis2, cluster);
    ++cluster;
  }
  
  cout << cluster-1 << ln;
  for (int i = 1; i <= n; ++i) cout << scc[i] << " ";
}

void dfs2(int node, vector<vi>& adj, vi& disc, vi& scc, stack<int>& st, vi& instack, vi& low, int& time, int& cnt) {
  disc[node] = low[node] = ++time;
  st.push(node);
  instack[node] = 1;

  for (int to: adj[node]) {
    if (!disc[to]) {
      dfs2(to, adj, disc, scc, st, instack, low, time, cnt);
      low[node] = min(low[node], low[to]);
    } else if (instack[to]) {
      low[node] = min(low[node], disc[to]);
    }
  }

  if (low[node] == disc[node]) {
    while (true) {
      int top = st.top(); st.pop();
      instack[top]=0;
      scc[top] = cnt;
      if (top == node) break;
    }

    ++cnt;
  }
} 

void tarjan() {
  int n, k, u, v; cin >> n >> k;

  vector<vi> adj(n+1);
  vector<int> scc(n+1), low(n+1), instack(n+1), disc(n+1);
  stack<int> st;

  rep(i, k) {
    cin >> u >> v;
    adj[u].pb(v);
  }
  int time = 1, cnt = 1;
  for(int i=1; i <= n; ++i) {
    if (!scc[i]) dfs2(i, adj, disc, scc, st, instack, low, time, cnt);
  }

  cout << cnt - 1 << ln;
  for (int i =1; i <= n; ++i) cout << scc[i] << " ";
  
}

int main() {
  flash;
  // kosaraju();
  tarjan();
  return 0;
}