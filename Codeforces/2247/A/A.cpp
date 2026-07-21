#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  int m = 0, p = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == -1) ++m;
    else ++p;
  }

  if ((n % 2 == 0 && (m % 2 == (n / 2) % 2))) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }

  // if (n % 2 || (n == 2 && a[1] == a[2])) {
  //   return;
  // }

  // cout << "YES" << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}