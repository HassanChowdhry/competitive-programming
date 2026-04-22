#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n + 5), cnt(1000005);

  for (int i =1; i <= n; ++i) {
    cin >> a[i];
  }

  int ans = 0, u = 0, l = 1, r = 1, ll = -1, rr = -1;

  while (r <= n) {
    if (cnt[a[r]] == 0) ++u;
    ++cnt[a[r]];

    while (l < r && u > k) {
      --cnt[a[l]];
      if (cnt[a[l]] == 0) --u;
      ++l;
    }
    // cout << l << " " << r << " " << u << "\n";
    if (r - l + 1 > ans) {
      ans = r - l + 1;
      ll = l;
      rr = r;
    }
    ++r;
  }

  // cout << ans << " " << ll << " " << rr;
  cout << ll << " " << rr;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}