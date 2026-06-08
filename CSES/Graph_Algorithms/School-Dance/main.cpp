#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int maxN = 505;
vector<vector<int>> adj(maxN);
int vis[maxN], mt[maxN];

int kuhn(int u) {
  if (vis[u]) return 0;

  vis[u] = 1;

  for (int v: adj[u]) {
    if (!mt[v] || kuhn(mt[v])) {
      mt[v] = u;
      return 1;
    }
  }

  return 0;
}

void solve() {
  cin >> n >> m >> k;

  int a, b;

  for (int i = 0; i < k; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    // cout << a << b << f << '\n';
  }


  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < maxN; ++j) vis[j] = 0;
    kuhn(i);
    // cout << ok;
    // cout << i << " ";
  }

  int cnt = 0;
  for (int i = 1; i < maxN; ++i) {
    if (!mt[i]) continue;
    ++cnt;
    // cout << i << " " << mt[i] << "\n";
  }
  cout << cnt << "\n";

  for (int i = 1; i < maxN; ++i) {
    if (!mt[i]) continue;
    cout << mt[i] << " " << i << "\n";
  }
}


int main() {
  solve();
  return 0;
}