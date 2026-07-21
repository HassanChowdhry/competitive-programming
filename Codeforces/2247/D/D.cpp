#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int c1 = 0, c0 = 0, m1 = 0, m0 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      if (a[i] == 1) c1++;
      else c0++;
    } else {
      if (a[i] == 1) m1++;
      else m0++;
    }
  }

  if (c1 == 0 && c0 == 0) {
    cout << 0 << "\n";
  } else if (c1 % 2 == 1) {
    cout << 1 << "\n";
  } else if (c1 >= 2 || (m1 > 0 && m0 > 0)) {
    cout << 2 << "\n";
  } else {
    cout << -1 << "\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}