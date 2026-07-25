#include <bits/stdc++.h>
using namespace std;

void solve() {
  int k; cin >> k;

  int t = 0, s = 0, n;
  for (int i = 1; i <= k; ++i) {
    cin >> n;
    if (n > t) {
      s = t;
      t = n;
    } else if (n > s) {
      s = n;
    }
  }

  if (t >= 3 || (t == 2 && s == 2)) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}