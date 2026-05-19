#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<long long> a(n + 1);
  vector<long long> x(m + 1);
  long long total = 0;
  vector<vector<long long>> p(2);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i % 2].push_back(a[i]);
    total += a[i];
  }

  sort(p[0].rbegin(), p[0].rend());
  sort(p[1].rbegin(), p[1].rend());

  for (int i = 1; i <= m; ++i) {
    cin >> x[i];
  }

  int i = 0, j = 0;
  int N = p[0].size(), M = p[1].size();

  long long mark = 0;
  for (int z = 1; z <= m; ++z) {
    int par = x[z] % 2;
    
    if (par) {
      if (j == M || (j >= 1 && p[1][j] <= 0)) continue;
      mark += p[1][j];
      ++j;
    } else {
      if (i == N || (i >= 1 && p[0][i] <= 0)) continue;
      mark += p[0][i];
      ++i;
    }
  }

  // for (int i = 0; i < 2; ++i) {
  //   for (int j: p[i]) {
  //     cout << j << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  long long res = total - mark;
  cout << res << "\n";
  
}

int main() {
  int t; cin >> t;
  while (t--)
  solve();

  return 0;
}