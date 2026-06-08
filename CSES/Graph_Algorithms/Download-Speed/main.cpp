#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxN = 501;
const long long INF = 1e9 + 7;
long long cap[maxN][maxN], parent[maxN];
vector<vector<int>> adj(maxN);

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

void maxflow() {
  long long flow = 0, add_flow = 0;

  while (true) {
    add_flow = bfs();
    if (add_flow == 0) break;

    flow += add_flow;
    int u = n;
    while (u != 1) {
      int v = parent[u];
      cap[u][v] += add_flow;
      cap[v][u] -= add_flow;
      u = v;
    }
  }

  cout << flow << "\n";
}

void solve() {
  cin >> n >> m;

  int a, b, f;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> f;

    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] += 1LL * f;
    // cout << a << b << f << '\n';
  }

  maxflow();
}


int main() {
  solve();
  return 0;
}