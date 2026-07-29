#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n, k; cin >> n >> k;

  if (n < (k + 2)) {
    cout << -1 << "\n";
    return;
  }

  int z = k / 2;
  int o = (k + 1) / 2;

  if (z) {
    cout << "00";
    n -= 2;
  }
  for (int i = 1; i < z; ++i) {
    cout << "0";
    --n;
  }

  if (!z) {
    cout << "0";
    --n;
  }

  if (o) {
    cout << "11";
    n -= 2;
  }

  for (int i = 1; i < o; ++i) {
    cout << "1";
    --n;
  }

  if (!o) {
    cout << "1";
    --n;
  }

  for (int i = 1; i <= n; ++i) {
    if (i % 2) cout << "0";
    else cout << "1";
  }

  cout << "\n";
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}