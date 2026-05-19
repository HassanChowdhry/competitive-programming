#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1), b(n + 1);
  vector<vector<int>> occ(n + 2);
  for (int i = 1 ;i <= n; ++i) {
    cin >> a[i];
  }
  
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    occ[a[i]].push_back(i);
    if (a[i] != b[i])
      occ[b[i]].push_back(i);
    
  }

  vector<int> fail(n + 1, n + 1);

  for (int i = n; i > 0; --i) {
    for (int j : occ[i]) {
      if (a[j] == i && b[j] == i) {
        auto it = upper_bound(occ[i + 1].begin(), occ[i + 1].end(), j);

        if (it == occ[i + 1].end()) { fail[j] = n + 1; continue; }

        int pos = *it;
        if (a[pos] == i + 1 && b[pos] == i + 1) {
          fail[j] = fail[pos];
        } else fail[j] = pos;
      }
    }
  }

  long long valid = 0;

  for (int i = 1; i <= n; ++i) {
    auto it = lower_bound(occ[1].begin(), occ[1].end(), i);
    int x = n + 1;
    if (it != occ[1].end()) {
      int pos = *it;
      if (a[pos] == 1 && b[pos] == 1) x = fail[pos];
      else x = pos;
    }

    valid += (x - i);
  }

  cout << valid << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}