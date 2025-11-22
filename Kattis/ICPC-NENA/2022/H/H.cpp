#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<int, int>
vector<vector<int>> edges;
vector<vector<ii>> adj(105);
int n, m, a, b;
int djik(int src, int dest) {
  priority_queue<ii,vector<ii>,greater<ii>> pq; pq.push({0, src});
  vector<int> dis(n + 1,1e9);
  dis[src] = 0;
  while (!pq.empty()) {
    auto [c, u] = pq.top(); pq.pop();
    if (u == dest) return c;
    if ( dis[u] != c ) {
      continue;
    }

    for ( auto [v, nc] : adj[u] ) {
      if ( dis[u] + nc < dis[v] ) {
        dis[v] = dis[u] + nc;
        pq.push({ dis[v], v });
      }
    }
  }
  return dis[dest];
}

void solve() {
  cin >> n >> m >> a >> b;  
  int u, v, c;

  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    edges.pb({ u, v, c });
    adj[u].pb({ v, c });
    adj[v].pb({ u, c });
  }

  int mn = djik(a, b);
  // cout << mn << "\n";
  int res = 0;
  for (int i = 0; i < m; ++i) {
    u = edges[i][0], v = edges[i][1], c = edges[i][2];
    int d1 = djik(a, u) + c + djik(v, b);
    int d2 = djik(a, v) + c + djik(u, b);
    if (d1 != mn && d2 != mn) res += c;
  }
  
  cout << res;
}

int main() {
  solve();
  return 0;
}