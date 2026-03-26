#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<long long> a(n);

  for (int i =0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    long long ans = 0, ans1 = 0, ans2 = 0;
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) {
        ++ans1;
      } else if (a[i] < a[j]) {
        ++ans2;
      }
    }
    ans = max(ans1, ans2);
    cout << ans << " ";
  }

  cout << "\n";
}

int main() {
  cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}