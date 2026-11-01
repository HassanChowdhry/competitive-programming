#include <bits/stdc++.h>
using namespace std;
int n, u, v, c;
vector<vector<int>> ans;
void solve() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> v;
      if (v == -1) continue;
      ans.push_back({i, j, v});
    }
  }

  cout << ans.size() << "\n";
  for (auto e : ans) {  
    u = e[0], v = e[1], c = e[2];
    cout << u << " " << v << " " << c << "\n";
  }
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}