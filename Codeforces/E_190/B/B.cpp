#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;

  int two = 0;
  int othree = 0;

  for (char c: s) {
    if (c == '4') {
      continue;
    }

    if (c == '2') {
      ++two;
    } else {
      othree = max(two, othree) + 1;
    }
  }

  int res = s.size() - max(two, othree);
  cout << res << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}