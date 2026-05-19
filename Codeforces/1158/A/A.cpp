#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n, m; cin >> n >> m;
  vector<long long> a(n), b(m);
  long long t1 = 0, t2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    t1 += a[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    t2 += b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (a[n - 1] > b[0]) {
    cout << -1; return;
  }

  if (a[n - 1] == b[0]) {
    long long res = t2;
    for (int i = 0; i < n-1; ++i) {
      res += (a[i] * m);
    }

    cout << res; return;
  }

  if (a[n - 1] < b[0]) {
    if (n == 1 || m == 1) {
      cout << -1; return;
    }

    long long res = t2 + a[n - 1] + a[n - 2] * (m - 1LL);
    for (int i = 0; i < n - 2; ++i) {
      res += (a[i] * m);
    }

    cout << res; return;
  }
}

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}