#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n; cin >> n;
  vector<long long> a(n + 1);

  for (long long i = 1; i <= n; ++i) cin >> a[i];

  for (long long i = 1; i < n; ++i) {
    if (a[i] < i) {
      cout << "NO" << "\n";
      return;
    }
    a[i + 1] += (a[i] - i);
    a[i] = i;
  }

  for (long long i = 1; i < n; ++i) {
    if (a[i + 1] <= a[i]) {
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