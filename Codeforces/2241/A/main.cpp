#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y; cin >> x >> y;

  if (x % y) cout << "NO\n";
  else cout << "YES\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}