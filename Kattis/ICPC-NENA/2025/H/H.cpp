#include <bits/stdc++.h>
using namespace std;

#define iiii pair<pair<long long, long long>, pair<long long, long long>>
#define ii pair<long long, long long>
#define fi first
#define se second

// cost, prev, node, tot
long long oo = 1e18;
priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
long long n, m, k, d, s, t, a, b, l, c, u, uv, du, lu, lv, pu, p;
long long con[101][101][101];
long long dist[101][101][101]; // node, l
long long cost[101][101];
vector<ii> adj[101];

void solve() {
  cin >> n >> m >> k >> d >> s >> t;

  for (int i = 1; i <= m; ++i) {
    cin >> a >> b >> l;
    adj[a].push_back({b, l});
    adj[b].push_back({a, l});
    cost[a][b] = l; cost[b][a] = l;
  }

  for (int i = 1; i <= k; ++i) {
    cin >> a >> b >> c;
    con[a][b][c] = 1;
  }

  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      for (int k = 0; k <= 100; ++k) {
        dist[i][j][k] = oo;
      }
    }
  } 

  dist[s][0][0] = 0;
  pq.push({{0, 0}, {s, 0}});

  while(!pq.empty()) {
    auto top = pq.top(); pq.pop();
    du = top.fi.fi; p = top.fi.se;
    u = top.se.fi; pu = top.se.se;

    if (du > dist[u][p][pu]) continue;

    if (u == t) {
      cout << du << "\n"; return;
      // cout << du << "\n"; return;
    }

    for (auto [v, uv] : adj[u]) {
      if (p == v) continue;
      if (con[p][u][v] && cost[p][u] + pu + uv > d) continue;
      // cout << p << " " << u << " " << v << "\n";

      // continue on continous road ?
      if (con[p][u][v] && dist[v][u][pu+uv] > du + uv) {
        dist[v][u][pu+uv] = du + uv;
        pq.push({{dist[v][u][pu+uv], u}, {v, cost[p][u] + pu}});
      }

      if (!con[p][u][v] && dist[v][u][0] > du + uv) {
        dist[v][u][0] = du + uv;
        pq.push({{dist[v][u][0], u}, {v, 0LL}});
      }
    }
  }
  cout << "impossible" << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}