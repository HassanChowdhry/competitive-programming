#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, q, a, b, c, u, v; cin >> n; 
 
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    // edges
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
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
 
  auto kth_ancestor = [&](int a, int k) -> int {
    for (int i = 0; i < LOG; ++i) {
      if (k & ( 1 << i )) a = dp[a][i];
    }
 
    return a;
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
 
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b >> c;
    
    // find the LCA, if LCA to b + LCA to a < c then ans = b
    // if LCA to a > c then cth ancestor of a
    // else LCA to b - c - LCA to a th ancestor of b
 
    int lca = LCA(a, b);
    int total_dist = depth[a] + depth[b] - depth[lca] * 2;
    
    if (total_dist <= c) {
      cout << b << "\n"; continue;
    }
    
    int dist_a = depth[a] - depth[lca];
    if (c <= dist_a) {
      cout << kth_ancestor(a, c) << "\n";
    } else {
      int k = total_dist - c;
      cout << kth_ancestor(b, k) << "\n";
    }
  }
}
 
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
  cout.tie(NULL);
 
  solve();
  return 0;
}