#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> vis(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  q.push(1);

  vector<int> red, blue;

  int f = 1;

  while (!q.empty()) {
    int l = q.size();

    for (int i = 0; i < l; ++i) {
      int u = q.front(); q.pop();
      if (vis[u]) continue;
      vis[u] = 1;

      if (f) {
        red.push_back(u);
      } else {
        blue.push_back(u);
      }
      
      for (int v: adj[u]) {
        if (vis[v]) continue;
        q.push(v);
      }
    }

    f = 1 - f;
  }
  
  int pick = (red.size() <= blue.size() ? 1 : 0);
  if (pick) {
    cout << red.size() << "\n";
    for (int i = 0; i < red.size(); ++i) {
      cout << red[i] << " ";
    }
  } else {
    cout << blue.size() << "\n";
    for (int i = 0; i < blue.size(); ++i) {
      cout << blue[i] << " ";
    }
  }

  cout << "\n";
}

int main() {
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}