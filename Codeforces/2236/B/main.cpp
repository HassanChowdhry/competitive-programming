#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
void solve() {
  cin >> n >> k >> s;
  vector<int> vis(n + 1);

  int ok = 1;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;

    int one = 0, zero = 0;
    for (int j = i; j < n; j+=k) {
      vis[j] = 1;
      if (s[j] == '0') ++zero;
      if (s[j] == '1') ++one;
    }

    // cout << " one : " << one << " zero : " << zero << "\n";

    if (one == 0) continue;

    if (one % 2) ok = 0;
    // else if (one % 2 && zero % 2) ok = 0;
  }

  if (ok) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}