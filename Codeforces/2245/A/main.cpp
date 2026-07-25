#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<char> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  if (n < k * 2) {
    cout << -1 << "\n";
    return;
  }

  int res = 0;
  for (int i = 1; i <= k; ++i ) {
    if (p[i] != 'R') ++res;
  }

  for (int i = n; i >= n - k + 1; --i) {
    if (p[i] != 'L') ++res;
  }

  cout << res << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}