#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, c; cin >> n >> c;

  vector<int> a(n), b(n); 
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int x = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      x = -1; break;
    }
    x += abs(a[i] - b[i]);
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  int y = c;
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      y = -1; break;
    }
    y += abs(a[i] - b[i]);
  }

  if (x == -1 && y == -1) cout << -1 << "\n";
  else if (x == -1) cout << y << "\n";
  else cout << x << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}