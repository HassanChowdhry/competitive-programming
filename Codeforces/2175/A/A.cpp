#include <bits/stdc++.h>
using namespace std; 
#define ln "\n"

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  vector<int> cnt(1005);
  int dist = 0;
  for (int i =0; i < n; ++i) {
    cin >> a[i];
    if (!cnt[a[i]]) ++dist;
    ++cnt[a[i]];
  }

  sort(a.begin(), a.end());
  auto it = lower_bound(a.begin(), a.end(), dist);
  cout << *it << ln;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}