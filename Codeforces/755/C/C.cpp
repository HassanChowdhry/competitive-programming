#include <bits/stdc++.h>
using namespace std;

void solve() {
  // dsu solves this

  int n; cin >> n;

  vector<int> parent(n + 1);
  vector<int> rank(n + 1, 1);

  for (int i = 0; i <= n; ++i ) parent[i] = i;

  auto find = [&](int x) -> int {
    while (parent[x] != parent[parent[x]]) {
      parent[x] = parent[parent[x]];
    }

    return parent[x];
  };

  auto onion = [&](int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py);

    if (rank[px] < rank[py])
      swap(px, py);
    
    rank[px] += rank[py];
    parent[py] = px;
  };

  int j;
  for (int i = 1; i <= n; ++i) {
    cin >> j;
    onion(i, j);
  }

  set<int> ans;
  for (int i = 1; i <= n; ++i) {
    ans.insert(find(i));
  }
  int res = ans.size();
  cout << res;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);
  solve();
  return 0;
}