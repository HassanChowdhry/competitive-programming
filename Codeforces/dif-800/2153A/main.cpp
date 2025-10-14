#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
  int n; cin >> n;
  set<int> u;
  for (int i =0; i < n; ++i) {
    int x; cin >> x;
    u.insert(x);
  }

  cout << u.size() << ln;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}