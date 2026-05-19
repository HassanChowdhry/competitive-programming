#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> size(n + 1, 1);
  vector<vector<int>> tree(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  auto dfs = [&](int u, int parent, auto&& dfs) -> void {
    for (int v: tree[u]) {
      if (v == parent) continue;
      dfs(v, u, dfs);
      size[u] += size[v];
    }

    return;
  };

  auto find = [&](int u, int parent, auto&& find) -> int {
    for (int v: tree[u]) {
      if (v == parent) continue;
      if (size[v] > n / 2) return find(v, u, find);
    }

    return u;
  };

  dfs(1, 0, dfs);
  // for (int i = 0; i <= n; ++i) {
    // cout << i << " : " << size[i] << "\n";
  // }
  int res = find(1, 0, find);
  cout << res;

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}