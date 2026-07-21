#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, m; 
  cin >> n >> k >> m;
  
  if (k > m || k > n) {
    cout << "NO\n"; return;
  }

  cout << "YES" << "\n";
  for (int i = 1; i <= n; ++i) {
    if (i % k == 0) {
      cout << (m - k + 1) << " ";
    } else {
      cout << 1 << " ";
    }
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

// k = 3, m = 5
// have to make 15 every k
// m - 3 + m - 2 + m - 1
// 4 2 4 3 1
// just need 1
// m - 1, m - 4, m - 1