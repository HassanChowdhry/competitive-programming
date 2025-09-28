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

int m, N;
vector<vi> g, rg;
vi comp, topo, vis, two_sat;

int var(int x, bool val) { return 2 * x ^ ( val ? 0 : 1 ); }  // map (x, true/false) to graph node

void add_clause(int x, bool xv, int y, bool yv) {
  // (xv ? x : ¬x) ∨ (yv ? y : ¬y)
  g[var(x, !xv)].pb(var(y, yv));
  g[var(y, !yv)].pb(var(x, xv));
  rg[var(x, xv)].pb(var(y, !yv));
  rg[var(y, yv)].pb(var(x, !xv));
}

// kosaraju
void dfs1(int node) {
  vis[node] = 1;
  for (int next: g[node]) if (!vis[next]) dfs1(next);
  topo.pb(node);
}
void dfs2(int node, int component) {
  comp[node] = component;
  vis[node] = 1;
  for (int next: rg[node]) if (!vis[next]) dfs2(next, component);
}

bool solve_2sat() {
  vis.assign(2 * N, 0);
  for (int i =0; i < 2*N; ++i) if (!vis[i]) dfs1(i);

  comp.assign(2 * N, -1);
  vis.assign(2 * N, 0);
  int component = 0;
  for (int i = 2 * N - 1; i >= 0; --i) {
    int v = topo[i];
    if (!vis[v]) dfs2(v, component++); 
  }

  two_sat.assign(N, 0);

  for (int i =0; i < N; ++i) {
    if (comp[2 * i] == comp[2 * i + 1]) return false; // contradiction
    two_sat[i] = (comp[2 * i] > comp[2 * i + 1]);
  }
  return true;
}


void solve() {
  cin >> m >> N;

  g.assign(2*N, {});
  rg.assign(2*N, {});

  for (int i = 0; i < m; ++i) {
    char c1, c2; int x1, x2; 
    cin >> c1 >> x1 >> c2 >> x2;
    --x1; --x2;
    add_clause(x1, c1=='+', x2, c2=='+');
  }

  if (solve_2sat()) {
    for (int i =0; i < N; ++i) cout << (two_sat[i] ? '+' : '-') << " ";
  } else {
    cout << "IMPOSSIBLE";
  }
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}