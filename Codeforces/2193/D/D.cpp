#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
  int n; cin >> n;
  long long res = 0;
  vector<long long> a(n), b(n), preb(n);
  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; ++i)  {
    cin >> b[i];
  }

  // think of it like moves, regardless of where the 1 sword is, its going to be wasted
  // bin search for the difficulty
  // answer has to be inside the array
  sort(a.begin(), a.end());

  preb[0] = b[0];
  for (int i = 1; i < n; ++i) {
    preb[i] = b[i] + preb[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    int moves = n - i;
    int level = upper_bound(preb.begin(), preb.end(), moves) - preb.begin();
    res = max(res, 1LL * level * a[i]);
  }

  cout << res << ln;
}

int main() {
  int t; cin >> t;
  while (t--)
    solve();
  return 0;
}