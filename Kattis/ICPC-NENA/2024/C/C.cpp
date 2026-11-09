#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, long long>
#define iii pair<pair<int, int>, long long>

int n, m, s, t, u, v, w;
long long c;
const int maxN = 1000;
const long long INF = 1e16;
long long cap[maxN][maxN], parent[maxN];
vector<long long> wires[maxN];
vector<int> adj[maxN];

void clear() {
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j <= t; ++j) {
            cap[i][j] = 0;
        }
    }

    for (int i = 0; i <= t; ++i) adj[i].clear();
}

void add_edge(int u, int v, long long c) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] += c;
}

long long bfs() {
  for (int i = 1; i <= t; ++i) {
    parent[i] = -1;
  }
  parent[0] = -2;

  queue<ii> q;
  q.push({ 0, INF });

  while (!q.empty()) {
    auto [u, f] = q.front(); q.pop();

    for (int v: adj[u]) {
      if (parent[v] == -1 && cap[u][v]) {
        parent[v] = u;
        long long f2 = min(f, cap[u][v]);
        if (v == t) return f2;
        q.push({ v, f2 });
      }
    }
  }

  return 0LL;
}

int maxflow(int k) {

  long long flow = 0, add_flow = 0;
  clear();

  for (int i = 1; i <= m; ++i) {
    u = wires[i][0], v = wires[i][1], c = wires[i][2];
    w = n + i;
    add_edge(0, w, c);
    add_edge(w, u, INF);
    add_edge(w, v, INF);
  }

  for (int i = 1; i <= n; ++i) {
    add_edge(i, t, k);
  }

  while (true) {
    add_flow = bfs();
    if (add_flow == 0) break;

    flow += add_flow;
    int u = t;
    while (u != 0) {
      int v = parent[u];
      cap[u][v] += add_flow;
      cap[v][u] -= add_flow;
      u = v;
    }
  }

  return n * k == flow;
}

void solve() {
  cin >> n >> m;
  s = 0, t = n + m + 1;
  long long a, b, f;
  long long total = 0;

  for (int i = 1; i <= m; ++i) {
    cin >> a >> b >> f;
    
    wires[i] = {a, b, f};
    total += f;
    // cout << a << b << f << '\n';
  }
  
  int l = 0, r = total/n;
  long long res = total;

  while (l <= r) {
    int k = (l + r) >> 1;
    if (maxflow(k)) {
        res = min(res, (total - 1LL * n * k));
        l = k + 1;
    } else {
        r = k - 1;
    }
  }

  cout << res << "";
  
}


int main() {
  solve();
  return 0;
}