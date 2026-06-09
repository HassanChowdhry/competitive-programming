#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxN = 501;
const long long INF = 1e9 + 7;
long long cap[maxN][maxN], parent[maxN];
vector<vector<int>> adj(maxN);
vector<vector<int>> ans;
int vis[maxN][maxN];

long long bfs() {
  for (int i = 1; i <= n; ++i) {
    parent[i] = -1;
  }
  parent[1] = -2;

  queue<pair<int, long long>> q;
  q.push({ 1, INF });

  while (!q.empty()) {
    auto [u, f] = q.front(); q.pop();

    for (int v: adj[u]) {
      if (parent[v] == -1 && cap[u][v]) {
        parent[v] = u;
        long long f2 = min(f, cap[u][v]);
        if (v == n) return f2;
        q.push({ v, f2 });
      }
    }
  }

  return 0LL;
}

int dfs(int u, vector<int>& path) {
  path.push_back(u);
  for (int v: adj[u]) {
    if (vis[u][v] == 0 && cap[u][v] == 0) {
      vis[u][v] = 1;
      if (v == n) return 1;
      int x = dfs(v, path);
      if (x) return x;
    }
  }

  path.pop_back();
  return 0;
}

void maxflow() {
  long long flow = 0, add_flow = 0;

  while (true) {
    add_flow = bfs();
    if (add_flow == 0) break;

    flow += add_flow;
    int u = n;
    while (u != 1) {
      int v = parent[u];
      // cout << v << " " << u << "\n";
      cap[u][v] += add_flow;
      cap[v][u] -= add_flow;
      u = v;
    }
  }

  cout << flow << "\n";

  int ok = 1;
  while (ok) {
    vector<int> path;
    ok = dfs(1, path);
    if (!ok) break;
    path.push_back(n);
    cout << path.size() << "\n";
    for (int node : path) {
      cout << node << " ";
    } cout << "\n";
  }
}

void solve() {
  cin >> n >> m;

  int a, b, f = 1;

  for (int i = 0; i < maxN; ++i) {
    for (int j = 0; j < maxN; ++j) {
      vis[i][j] = -1;
    }
  }

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] += 1LL * f;
    vis[a][b] = 0;
    // cout << a << b << f << '\n';
  }

  maxflow();
}


int main() {
  solve();
  return 0;
}