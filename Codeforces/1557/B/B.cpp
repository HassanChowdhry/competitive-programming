# include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> a(n);

  for (int i = 0; i < n; ++i) {
    int b; cin >> b;
    a[i] = { b, i };
  } 

  sort(a.begin(), a.end());
  int l = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i].second != a[i-1].second + 1) ++l;
  }

  // cout << l << " ";
  cout << ((l > k) ? "no" : "yes") << "\n";
}

int main() {
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}