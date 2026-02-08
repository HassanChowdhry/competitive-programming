#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, t; cin >> n >> t;
  vector<int> a(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  } 

  sort(a.begin(), a.end());

  for (int i = 0; i < n; ++i) {
    if (t < a[i]) break;
    t -= a[i];
    ++res;
  }

  cout << res;
}

int main() {
  solve();
  return 0;
}