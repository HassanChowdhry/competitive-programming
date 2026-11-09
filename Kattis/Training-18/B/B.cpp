#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxN = 4005;
const int INF = 1e9;
long long cap[maxN][maxN], parent[maxN];
vector<vector<int>> adj(maxN);
int vis[maxN];

void add_edge(int u, int v, int c) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] += c;
}

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

long long maxflow() {
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

  return flow;
}

void solve() {
  cin >> n >> m;


  int p = n;
  n = 2 * p + 2;
  int a, b;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;

    add_edge(a+1, b + p + 1, INF);
    add_edge(b+1, a + p + 1, INF);
    // cout << a << b << f << '\n';
  }

  string team; cin >> team;
  
  for (int v = 1; v <= p; ++v ) {
    int v1 = v + 1;
    int v2 = v + p + 1;


    add_edge(v1, v2, INF);

    if (team[v-1] == '0') {
        add_edge(1, v1, 2);
        add_edge(v2, n, 1);
    } else {
        add_edge(1, v1, 1);
        add_edge(v2, n, 2);
    }
  }

//   cout << p << " ";
  long long res = maxflow() - p;
  cout << res;
}


int main() {
  solve();
  return 0;
}