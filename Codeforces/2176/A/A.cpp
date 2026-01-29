#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i =0; i < n; ++i) cin >> a[i];

  int ans = 0;
  int curr = a[0];
  for (int i = 1; i < n; ++i) {
    if (curr > a[i]) ++ans;
    else curr = a[i]; 
  }

  cout << ans << ln;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}