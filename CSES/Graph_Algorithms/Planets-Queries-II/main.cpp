#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
const int LOG = 20;
vector<vector<int>> adj(maxN);
int up[LOG][maxN];
vector<int> cycles;

int dsu[maxN], comps[maxN], d[maxN], cyc[maxN];

int find(int x) {
  if (dsu[x] < 0) return x;
  dsu[x] = find(dsu[x]);
  return dsu[x];
}

int onion(int x, int y) {
  int px = find(x), py = find(y);
  if (px == py) return 0;

  if (dsu[px] < dsu[py]) swap(px, py);
  dsu[py] += dsu[px];
  dsu[px] = py;
  return 1;
}

void dfs(int u, int id) {
  comps[u] = id;

  for (int v: adj[u]) {
    if (!comps[v]) {
      d[v] = d[u] + 1;
      dfs(v, id);
    } else cyc[u] = d[u] + 1;
    cyc[u] = max(cyc[u], cyc[v]);
  }
}

int lift(int a, int k) {
  int u = a;
  for (int p = LOG - 1; p >= 0; --p) {
    if (k & ( 1 << p)) u = up[p][u];
  }
  return u;
}

int query(int a, int b) {
  if (a == b) return 0;

  // cout << a << " " << b << "\n";
  // cout << comps[a] << " " << comps[b] << "\n\n";
  if (comps[a] != comps[b]) {
    return -1;
  }

  // cout << "HERE" << "\n";
  if (cyc[a]) {
    if (!cyc[b]) {
      return -1;
    }

    int t = ((d[a] - d[b] + cyc[a]) % cyc[a]);
    return t;
  }

  if (!cyc[b]) {
    if (d[a] <= d[b]) {
      return -1;
    }
    
    int t = d[a] - d[b];
    int dest = lift(a, t);
    if (dest == b) {
      return t;
    } else {
      return -1;
    }

  }

  int u = a;
  for (int p = LOG - 1; p >= 0; --p) {
    int parent = up[p][u];
    if (!cyc[parent]) {
      u = parent;
    }
  }

  u = up[0][u];

  int t = (d[a] - d[u]) + query(u, b);

  return t;
}

void solve() {
  int n, q; cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    dsu[i] = -1;
  }

  for (int i = 1; i <= n; ++i) {
    int v; cin >> v;
    adj[v].push_back(i);
    up[0][i] = v;
    if (!onion(v, i)) {
      cycles.push_back(v);
    }
  }

  for (int p = 1; p < LOG; ++p) {
    for (int i = 1; i <= n; ++i) up[p][i] = up[ p - 1 ][ up[p - 1][i] ];
  }

  int component = 1;
  for (int node: cycles) {
    dfs(node, component++);
  }

  int a, b;
  while (q--) {
    cin >> a >> b;
    int t = query(a, b);

    cout << t << "\n";
  }
}

int main() {
  // int t; cin >> t;
  // rep(i, t) 
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}