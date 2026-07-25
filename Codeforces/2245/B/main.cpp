#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  long long c; 
  
  cin >> n >> c;

  vector<long long> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; a[i] -= c;
  }

  if (n == 1) {
    cout << a[1] << "\n";
    return;
  }

  // cout << "BEGIN: n: " << n << " C: " << c << "\n";
  sort(a.begin() + 1, a.end());

  long long res = 0;
  int m = n / 2;
  for (int i = n; i > m; --i) {
    int j = n - i + 1;

    // cout << a[i] << " " << a[j] << "\n";
    res += a[i];
    if (a[j] > 0 && i != j) res += a[j];
  }

  cout << res << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}