#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int LOG = 20;
  vector<vector<int>> dp(n + 1, vector<int>(LOG)); 
  vector<int> depth(n + 1);
  vector<int> parent(n + 1);
 
  auto getDepth = [&](int u, int p, int d, auto&& getDepth) {
    if (depth[u]) return;
    depth[u] = d;
    for (int v: adj[u]) {
    if (v == p) continue;
      parent[v] = u;
      getDepth(v, u, d + 1, getDepth);
    }
  };
 
  auto LCA = [&](int a, int b) -> int {
    if (depth[a] > depth[b]) swap(a, b);
    int k = depth[b] - depth[a];
    for (int i = 0; i < LOG; ++i) {
      if (k & ( 1 << i )) b = dp[b][i];
    }
 
    if (a == b) { return a; }
 
    for (int log = LOG-1; log >= 0; --log) {
      if (log >= depth[a]) continue;
      if (dp[a][log] != dp[b][log]) {
        a = dp[a][log]; b = dp[b][log];
      }
    }
    return dp[a][0];
  };
 
  getDepth(1, 0, 0, getDepth);
 
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = parent[i];
  }
 
  for (int p = 1; p < LOG; ++p) {
    for (int i = 1; i <= n; ++i) {
      dp[i][p] = dp[ dp[i][p - 1] ][p-1];
    }
  }

  vector<int> tree(n + 1);
  vector<int> res(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;

    int lca = LCA(a, b);
    int lca_p = dp[lca][0];
    ++tree[a]; ++tree[b];
    --tree[lca];
    // cout << a << " " << b << " " << lca << " " << lca_p << '\n';
    if (lca_p) {
      --tree[lca_p];
    }
  }
  
  auto dfs = [&](int u, int p, auto&& dfs) -> int {
    int ans = tree[u];
    for (int v: adj[u]) {
      if (v == p) continue;
      ans += dfs(v, u, dfs);
    }

    return res[u] = ans;
  };

  dfs(1, 0, dfs);
  for (int i = 1; i <= n; ++i) {
    // cout << tree[i] << " ";
    cout << res[i] << " ";
  }
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);
  solve();
  return 0;
}