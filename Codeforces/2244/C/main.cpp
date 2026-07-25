#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n, x, y; cin >> n >> x >> y;
  vector<long long> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int g = gcd(x, y);

  for (int i = 1; i <= n; ++i) {
    if (a[i] % g != i % g) {
      cout << "NO" << "\n";
      return;
    }
  }
  
  cout << "YES" << "\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();

  return 0;
}