#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, q; cin >> n >> k >> q;
  int l, r;
  vector<int> pre(200005);
  vector<int> ans(200005);

  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    ++pre[l];
    --pre[r + 1];
  }

  for (int i = 1; i < 200005; ++i) {
    pre[i] += pre[i-1];
  }

  for (int i = 1; i < 200005; ++i) {
    ans[i] = ans[i - 1] + (pre[i] >= k);
  }

  // for (int i = 90; i <= 100; ++i) {
  //   cout << i << " : " << pre[i] << " ans: " << ans[i] << "\n";
  // }

  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    cout << ans[r] - ans[l - 1] << "\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}