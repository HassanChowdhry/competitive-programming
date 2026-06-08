#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  vector<long long> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  for (int i = 0; i < n; ++i) {

    vector<long long> a(n), b(n);
    long long maxx = 0;
        
    for (int j = 0; j < n - 1; ++j) {
      int p = (i + j) % n;
      int pj = (p + 1) % n;
      maxx = max(maxx, h[p]);
      a[pj] = maxx;
    }

    maxx = 0;
    
    for (int j = 0; j < n - 1; ++j) {
      int p = ((i - j + n) % n);
      int pj = (((p - 1) + n) % n);
      maxx = max(maxx, h[pj]);
      b[pj] = maxx;
    }

    for (int j = 0; j < n; ++j) {
      cout << a[j] << " ";
    } cout << "\n";
    for (int j = 0; j < n; ++j) {
      cout << b[j] << " ";
    } cout << "\n\n";

    long long ans = 0;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      ans += min(a[j], b[j]);
    }

    
    // cout << ans << " ";
    
    // int minn = 1e9 + 7;
    // for (int j = 0; j < n-1; ++j) {
    //   int p = (i + j) % n;
    //   int pj = ((p + 1) % n);
      
    //   minn = min(minn, h[p]);
    //   a[pj] = minn;
    // }

    // minn = 1e9 + 7;
    // for (int j = 0; j < n-1; ++j) {
    //   int p = ((i - j + n) % n);
    //   int pj = (((p - 1) + n) % n);
      
    //   minn = min(minn, h[pj]);
    //   b[pj] = minn;
    // }

    // int ans = 0;

    // for (int j = 0; j < n; ++j) {
    //   if (j == i) continue;
    //   ans += min(a[j], b[j]);
    // }

    // int ans1 = 0, ans2 = 0;

    // for (int j = 0; j < n; ++j) {
    //   ans1 += a[j];
    //   ans2 += b[j];
    // }
    // for (int j = 0; j < n; ++j) {
    //   cout << a[j] << " ";
    // } cout << "\n";
    // for (int j = 0; j < n; ++j) {
    //   cout << b[j] << " ";
    // }
    
    // cout << "\n\n";
    // cout << ans << " ";
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