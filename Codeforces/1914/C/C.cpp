#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;

  vector<long long> a(n + 1), b(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; a[i] += a[i-1];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    b[i] = max(b[i], b[i - 1]);
  }
  long long res = 0;
  int r = min(k, n);
  for (int i = r; i > 0; --i) {
    res = max(
      res,
      a[i] + b[i] * (k - i)*1LL
    );
  }

  cout << res << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}