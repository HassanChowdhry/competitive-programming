#include <bits/stdc++.h>
using namespace std;

int n, k, m, u, v;
vector<int> g[5005], rg[5005];
int comp[5005], vis[5005], two_sat[5005];
vector<int> topo;

int var(int x, bool val) { return 2 * x ^ ( val ? 0 : 1 ); }  // map (x, true/false) to graph node

void add_clause(int x, bool xv, int y, bool yv) {
  // (xv ? x : ¬x) ∨ (yv ? y : ¬y)
  g[var(x, !xv)].push_back(var(y, yv));
  g[var(y, !yv)].push_back(var(x, xv));
  rg[var(x, xv)].push_back(var(y, !yv));
  rg[var(y, yv)].push_back(var(x, !xv));
}

// kosaraju
void dfs1(int node) {
  vis[node] = 1;
  for (int next: g[node]) if (!vis[next]) dfs1(next);
  topo.push_back(node);
}
void dfs2(int node, int scc) {
  comp[node] = scc;
  vis[node] = 1;
  for (int next: rg[node]) if (!vis[next]) dfs2(next, scc);
}

bool twosat() {
  for (int i = 1; i <= 2*n; ++i) if (!vis[i]) dfs1(i);
  int scc = 1;
  for (int i = 2 * n; i >= 1; --i) {
    int v = topo[i];
    if (!vis[v]) dfs2(v, scc);
    ++scc; 
  }

  for (int i = 1; i <= n; i+=2) {
    if (comp[i] == comp[i + 1]) return false; // contradiction
    two_sat[i] = (comp[i] < comp[i + 1]);
  }
  return true;
}


void solve() {
  cin >> n >> k >> m;

  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    add_clause(u, 0, v, 0);
  }

//   for (int u = 1; u <= k; ++u) {
//     for (int v = k + 1; v <= n; ++v) {
//         add_clause(u, 1, v, 1);
//     }
//   }

  if (twosat()) {
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; ++i) cout << (two_sat[i]) << " ";
  } else {
    cout << "IMPOSSIBLE\n";
  }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}