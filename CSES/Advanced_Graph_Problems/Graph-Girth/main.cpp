#include <bits/stdc++.h>
using namespace std;

const int maxN = 2501;
int n, m;
int vis[maxN];
vector<int> adj[maxN];
queue<pair<int, int>> q; // curr_node, parent

void reset() {
  fill(vis + 1, vis + n + 1, 0);
  while (!q.empty()) q.pop();
}

int bfs(int start) {
  q.push({ start, -1 });
  vis[start] = 1;
  int len = 0;
  while (!q.empty()) {
    int level = q.size();
    ++len;
    int ans = 6000;
    for (int i = 0; i < level; ++i) {
      auto [u, p] = q.front(); q.pop();
      for (int v: adj[u]) {
        if (p == v) continue;
        if (vis[v]) { ans = min(len + vis[v], ans); continue; }
        
        vis[v] = len;
        q.push({ v, u });
      }
    }
    if (ans != 6000) return ans;
  }

  return 6000;
}

void solve() {
  cin >> n >> m;
  int ans = 6000;
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 

  for (int i = 1; i <= n; ++i) {
    reset();
    int res = bfs(i);
    ans = min(ans, res);
  }

  if (ans == 6000) cout << -1;
  else cout << ans;
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}