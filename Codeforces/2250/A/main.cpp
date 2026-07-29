#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  if (n == 1 || n % 2) {
    cout << "NO\n"; return;
  }

  int mn = 1e9 + 1, mx = 0;
  
  for (int i = 1; i <= n; i += 2) {
    mn = min(mn, a[i]);
  }
  for (int i = 2; i <= n; i += 2) {
    mx = max(mx, a[i]);
  }

  mn -= 1;
  mx += 1;
  
  if (mn < mx) {
    cout << "NO\n";
  } else cout << "YES\n";

  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}