#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());

  int ok = 1;
  for (int i = 1; i < n - 1; ++i) {
    if ((a[i - 1] % a[i]) != a[i + 1]) {
      ok = 0; break;
    }
  }

  if (ok) {
    cout << a[0] << " " << a[1] << "\n";
  } else cout << -1 << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while (t--)
  solve();
  return 0;
}