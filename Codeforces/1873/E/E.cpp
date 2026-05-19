#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  vector<long long> a(n + 2);
  
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<long long> pre(n + 2), suf(n + 2);

  auto valid = [&](long long h) -> bool {
    a[0] = h, a[n + 1] = h;
    long long curr = 0;

    for (int i = 1; i <= n; ++i) {
      curr += max(0LL, h - a[i]);
      if (curr > x) return false;
    }
    
    return curr <= x;
  };

  long long l = 1, r = 2e9;
  long long res = 1;
  while (l <= r) {
    long long mid = (l + r) / 2LL;

    if (valid(mid)) {
      l = mid + 1;
      res = mid;
    } else {
      r = mid - 1;
    }
  }

  cout << res << "\n";
  
}

int main() {
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}