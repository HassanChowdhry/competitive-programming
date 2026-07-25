#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  long long res = 3;
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  if (n == 2) {
    cout << -1 << "\n";
    return;
  }

  cout << 1 << " " << 2 << " ";
  for (int i = 3; i <= n; ++i) {
    cout << res << " ";
    res *= 2;
  }

  cout << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}