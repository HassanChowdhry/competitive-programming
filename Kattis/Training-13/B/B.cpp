#include <bits/stdc++.h>
using namespace std;

void solve() {
  double y; cin >> y;
  int x = round(1.0 + y + (y * y) + (y * y * y));

  cout << x;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}