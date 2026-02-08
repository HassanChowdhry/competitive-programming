#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k, n, w; cin >> k >> n >> w;

  cout << abs(min(0, n - (k * ((w * (w + 1)) / 2))));
}

int main() {
  solve();
  return 0;
}