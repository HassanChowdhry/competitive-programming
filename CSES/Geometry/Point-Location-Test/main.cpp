#include <bits/stdc++.h>
using namespace std;

void solve() {
  // cross product
  // p1, p2, p3
  // (x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1)
  // if 0 -> TOUCH
  // if +ve -> left
  // if -ve -> right

  long x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  long o = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
  if (o == 0) cout << "TOUCH\n";
  else if (o < 0) cout << "RIGHT\n";
  else if (o > 0) cout << "LEFT\n";

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}