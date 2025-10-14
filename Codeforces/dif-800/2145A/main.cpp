#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
  int n; cin >> n;
  int rem = n % 3;
  if (rem == 0) cout << 0 << ln;
  else cout << 3-rem << ln;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}