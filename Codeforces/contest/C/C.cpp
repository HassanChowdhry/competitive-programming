#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
  int n; cin >> n;
  if (query(1, 2) == 1) { cout << "! 1" << "\n"; cout.flush(); return; }
  if (query(2, 3) == 1) { cout << "! 2" << "\n"; cout.flush(); return; }
  if (query(3, 1) == 1) { cout << "! 3" << "\n"; cout.flush(); return; }

  int nxt = 4;
  for (int i = 0; i < n - 2; ++i) {
    if (query(nxt, nxt + 1) == 1) {
      cout << "! " << nxt << "\n";
      cout.flush(); return;
    }
    nxt += 2;
  }
  cout << "! " << 2 * n << "\n";
  cout.flush();
}

int main() {
  cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}