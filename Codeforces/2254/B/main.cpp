#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> pre(n + 1);
  vector<int> suf(n + 1);
  s = " " + s; pre[1] = 1; suf[n] = 1;

  for (int i = 2; i <= n; ++i) {
    pre[i] = pre[i - 1];
    if (s[i] != s[i-1]) {
      ++pre[i];
    }
  }

  for (int i = n-1; i >= 1; --i) {
    suf[i] = suf[i + 1];
    if (s[i] != s[i+1]) {
      ++suf[i];
    }
  }

  int ans = n;
  for (int i = 2; i < n; ++i) {
    if (s[i-1] == s[i+1]) {
      ans = min(ans, pre[i-1] + suf[i+1] - 1);
    } else {
      ans = min(ans, pre[i-1] + suf[i+1]);
    }
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}