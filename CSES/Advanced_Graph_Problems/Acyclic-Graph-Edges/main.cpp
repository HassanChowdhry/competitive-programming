#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
vector<int> adj[maxN];
int vis[maxN];
map<int, map<int, int>> cnt;

// could use edge id as well
void dfs(int u, int p) {
  vis[u] = 1;
  for (int v: adj[u]) {
    if (v == p) continue;

    if (vis[v] == 0) {
      cout << u << " " << v << "\n";
      --cnt[u][v]; --cnt[v][u];
      dfs(v, u);
    } else if (vis[v] == 1) {
      --cnt[u][v]; --cnt[v][u];
      cout << v << " " << u << "\n";
    } else if (vis[v] == 2) {
      if (cnt[u][v]) {
        cout << u << " " << v << "\n";
        --cnt[u][v]; --cnt[v][u];
      }
    } 
  }
  // cout << "\n";

  vis[u] = 2;
}

void solve() {
  int n, m; cin >> n >> m;

  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++cnt[u][v]; ++cnt[v][u];
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    dfs(i, -1);
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
