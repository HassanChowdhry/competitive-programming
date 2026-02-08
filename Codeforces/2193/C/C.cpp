#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 2), b(n + 2), pre(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  for (int i = n ; i > 0; --i) {
    a[i] = max({a[i], a[i + 1], b[i]});
  }

  for (int i = 1; i <= n; ++i) {
    pre[i] = a[i] + pre[i - 1];
  }

  int l, r;
  while (q--) {
    cin >> l >> r;

    cout << pre[r] - pre[l - 1] << " ";
  }  cout << ln;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}

