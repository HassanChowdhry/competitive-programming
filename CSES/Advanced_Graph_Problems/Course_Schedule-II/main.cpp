#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> cnt(n + 1);
  priority_queue<int> pq;

  for (int i = 1; i <= m; ++i) {
    int p, c; cin >> p >> c;
    adj[c].push_back(p);
    ++cnt[p];
  }

  for (int i = 1; i <= n; ++i) {
    if (!cnt[i]) pq.push(i);
  }

  vector<int> res;
  while (!pq.empty()) {
    int u = pq.top(); pq.pop();

    res.push_back(u);

    for (int v: adj[u]) {
      --cnt[v];
      if (!cnt[v]) pq.push(v);
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    cout << res[i] << " ";
  }
}

int main() {
  solve();
  return 0;
}
