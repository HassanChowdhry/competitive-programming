#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  int len = 0;
  int res = 0;

  int ok = 0;
  char c;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    if (c == '#') {
      if (!ok) {
        ok = 1; len = 0;
      }
      ++len;
    } else {
      ok = 0;
    }
    res = max(res, ((len + 1) / 2));
  }

  cout << res << "\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();

  return 0;
}