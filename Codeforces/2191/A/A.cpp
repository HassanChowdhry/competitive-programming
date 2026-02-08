#include <bits/stdc++.h>
using namespace std;

#define ln "\n"

void solve() {
  int n; cin >> n;
  vector<int> a(n + 5);
  vector<int> check(n + 5);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; check[a[i]] = i;
  }

  int ok = 1;
  
  for (int i = 2; i < n; ++i) {
    // cout << (check[i] & 1) << " " << (check[i - 1] & 1) << " " << (check[i + 1] & 1) << ln;
    // cout << (check[i] & 1 == check[i - 1] & 1) << " " << (check[i] & 1 == check[i + 1] & 1) << ln;
    if (((check[i] & 1) == (check[i - 1] & 1)) || 
        ((check[i] & 1) == (check[i + 1] & 1))
    ) { ok = 0; break; }
  }

  if (ok) cout << "YES" << ln;
  else cout << "NO" << ln;
  
}

int main() {
  int t; cin >> t;
  while (t--) solve();

  return 0;
}