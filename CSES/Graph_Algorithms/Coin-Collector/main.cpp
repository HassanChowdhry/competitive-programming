#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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

const ll MAXN = 100005;
vector<ll> top;
vector<vl> adj(MAXN), radj(MAXN), scc(MAXN);
vector<ll> value(MAXN), coins(MAXN);
map<ll, ll> ccs;
map<ll, set<ll>> sccadj;
vector<ll> dp(MAXN);
ll vis[MAXN], vis2[MAXN], vis3[MAXN];

void dfs(int u) {
  vis[u] = 1;
  for (int v: adj[u]) if (!vis[v]) dfs(v);
  top.pb(u);
}

ll dfs2(int u, int group) {
  ll money = coins[u];
  vis2[u] = 1;
  for (ll v: radj[u]) if (!vis2[v]) { money += dfs2(v, group); };
  scc[group].pb(u);
  return money;
}

ll dfs3(int u) {
  if (dp[u]) return dp[u];
  ll res = value[u];
  ll curr = 0;
  for (ll v: sccadj[u]) {
    curr = max(curr, dfs3(v));
  }
  
  return dp[u] = (res + curr);
}

void solve() {
  int n, m; cin >> n >> m;
  fill(vis, vis + MAXN, 0);
  fill(vis2, vis2 + MAXN, 0);

  for (ll i=1; i <= n; ++i) cin >> coins[i];
  ll u, v;
  for (ll i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
  }
  
  // SCC to make a DAG
  // toposort
  for (ll i = 1; i <= n; ++i) if (!vis[i]) dfs(i);

  // scc -- reverse the toposort
  int group = 1;
  for (int i = n-1; i >= 0; --i) {
    if (!vis2[top[i]]) { 
      ll money = dfs2(top[i], group); 
      value[group] = money;
      ++group; 
    }
  }

  for (int i = 1; i < group; ++i) {
    for (int num: scc[i]) {
      ccs[num] = i;
    }
  }

  // transform adj list to SCC adj
  for (int i = 1; i <= n; ++i) {
    for (int num: adj[i]) {
      if (ccs[i] == ccs[num]) continue;
      sccadj[ccs[i]].insert(ccs[num]);
      vis3[ccs[num]] = 1;
    }
  }

  vector<ll> root;
  for (int i = 1; i < group; ++i) {
    if (!vis3[i]) root.pb(i);
  }
  
  ll res = -1;
  for (int num: root) {
    res = max(res, dfs3(num));
  }
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}