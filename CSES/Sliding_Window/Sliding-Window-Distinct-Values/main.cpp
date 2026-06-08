#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n, k; cin >> n >> k;

  vector<int> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int x = 0;
  map<int, int> cnt;

  for (int i = 1; i < k; ++i) {
    if (!cnt[a[i]]) ++x;
    ++cnt[a[i]];
  }
  int j = 1;
  for (int i = k; i <= n; ++i) {
    if (!cnt[a[i]]) ++x;
    ++cnt[a[i]];

    cout << x << " ";

    --cnt[a[j]];
    if (!cnt[a[j]]) --x;
    ++j;
  }
}

int main() {

  solve();
  return 0;
}