#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = 100 / a[i];
  }

  sort(a.begin(), a.end());
  int r = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] > r + 1) {
      cout << "NO" << "\n";
      return;
    }
    r += 100;
  }

  cout << "YES" << "\n";
}

int main() {
  int t; cin >> t;
  while (t--)
  solve();

  return 0;
}