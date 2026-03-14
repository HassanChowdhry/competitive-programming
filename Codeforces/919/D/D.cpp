#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, u, v; cin >> n >> m;
  string s; cin >> s; s = " " + s;

  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1);

  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
  }
  
  auto dfs = [&](int u, auto&& dfs) -> bool {
    if (vis[u] == 2) return false;

    for (int v: adj[u]) {
      if (vis[v] == 0) {
        vis[v] = 1;
        bool x = dfs(v, dfs);
        if (x) return x;
      } else if (vis[v] == 1) return true;
    }

    vis[u] = 2;
    return false;
  };

  
  for (int i = 1; i <= n; ++i) {
    bool cycle = dfs(i, dfs);
    if (cycle) { cout << -1; return; }
  }
  
  vector<int> topnum; vector<int> vis2(n + 1);
  auto topo = [&](int u, auto&& topo) {
    if (vis2[u]) return;
    
    for (int v: adj[u]) {
      topo(v, topo);
    }
    topnum.push_back(u);
    vis2[u] = 1;
  };
  
  for (int i = 1; i <= n; ++i) {
    topo(i, topo);
  }
  
  reverse(topnum.begin(), topnum.end());
  
  vector<vector<int>> dp(n + 1, vector<int>('z' + 5));
  for (int i = 1; i <= n; ++i) {
    ++dp[i][s[i]];
  }

  for (int u : topnum) {
    for (int v: adj[u]) {
      for (int i = 'a'; i <= 'z'; ++i) {
        if (i == s[v]) {
          dp[v][i] = max(dp[v][i], dp[u][i] + 1);
        } else {
          dp[v][i] = max(dp[v][i], dp[u][i]);
        }
      }
    }
  }

  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    for (int c = 'a'; c <= 'z'; ++c) {
      ans = max(ans, dp[i][c]);
    } 
  }

  cout << ans;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  cout.tie(NULL);

  solve();
  return 0;
}