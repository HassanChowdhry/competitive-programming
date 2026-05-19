#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<long long> a(n + 2), p(n + 2);

  for (int i = 1; i <= n; ++i) {
    a[i] = s[i-1] - '0';
    p[i] = p[i-1] + a[i-1];
  }

  map<long long, long long> cnt; // store, cnt of that;
  long long res = 0;

  for (int i = 1; i <= n; ++i) {
    long long store = p[i] - i*1LL + 1LL;
    ++cnt[store];
    long long check = a[i] + p[i] - i*1LL;
    res += cnt[check];
    // cout << "i: " << i << " ";
    // cout << " store: " << store << " ";
    // cout << " check: " << check << " ";
    // cout << "\n";
  }

  cout << res << "\n";
}

int main() {
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}