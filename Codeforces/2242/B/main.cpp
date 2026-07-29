#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1), p1(n + 2), p2(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] == 1) {
      p1[i]=p1[i-1]+1;
      p2[i]=p2[i-1]+1;
    } else if (a[i] == 2) {
      p1[i]=p1[i-1]-1;
      p2[i]=p2[i-1]+1;
    } else {
      p1[i]=p1[i-1]-1;
      p2[i]=p2[i-1]-1;
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << p1[i] << " ";
  // } cout << "\n";
  // for (int i = 1; i <= n; ++i) {
  //   cout << p2[i] << " ";
  // } cout << "\n";

  int mn = 1e9+7;
  if (p1[1] >= 0) {
    mn = min(mn, p2[1]);
  }

  int ok = 0;
  for (int i = 2; i < n; ++i) {
    if (p2[i] >= mn) {
      ok = 1; break;
    }
    if (p1[i] >= 0) mn = min(mn, p2[i]);
  }

  if (ok) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}